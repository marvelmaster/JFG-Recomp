#include "common/rt64_math.h"
#include <cmath>
#include <cstdio>

static bool close(float a, float b) { return std::abs(a - b) < 0.0001f; }

int main() {
    // Row-vector convention: translated X, projective W = z + 1.
    const hlslpp::float4x4 matrix(1,0,0,0, 0,1,0,0, 0,0,1,1, 2,0,0,1);
    const RT64::DecomposedTransform d(matrix);
    if (!d.valid) return 1;
    const auto rebuilt = RT64::recomposeMatrix(d.rotation, d.scale, d.skew, d.translation, d.perspective);
    std::printf("original W column: %.6f %.6f %.6f %.6f\n", float(matrix[0][3]), float(matrix[1][3]), float(matrix[2][3]), float(matrix[3][3]));
    std::printf("rebuilt W column:  %.6f %.6f %.6f %.6f\n", float(rebuilt[0][3]), float(rebuilt[1][3]), float(rebuilt[2][3]), float(rebuilt[3][3]));
    const auto pos = hlslpp::float4(1,0,1,1);
    const auto originalPoint = hlslpp::mul(pos, matrix);
    const auto rebuiltPoint = hlslpp::mul(pos, rebuilt);
    std::printf("original point X/W: %.6f / %.6f = %.6f\n", float(originalPoint.x), float(originalPoint.w), float(originalPoint.x / originalPoint.w));
    std::printf("rebuilt point X/W:  %.6f / %.6f = %.6f\n", float(rebuiltPoint.x), float(rebuiltPoint.w), float(rebuiltPoint.x / rebuiltPoint.w));
    // The JFG policy disables decomposition and skips all component interpolation.
    const auto preserved = RT64::lerpMatrixComponents(matrix, matrix, false, false, false, 0.5f);
    for (unsigned r = 0; r < 4; ++r)
        for (unsigned c = 0; c < 4; ++c)
            if (!close(float(preserved[r][c]), float(matrix[r][c]))) return 2;
    // Regression diagnostic passes when actual RT64 exhibits the proven defect
    // and its existing no-decomposition path preserves the original matrix.
    if (!close(float(rebuilt[0][3]), -2) || !close(float(rebuilt[3][3]), -3)) return 3;
    std::puts("PASS: RT64 projective roundtrip defect reproduced; JFG preservation policy verified.");
    return 0;
}
