#ifndef MATHEMATICS_TYPES_H
#define MATHEMATICS_TYPES_H

#include "linalg.h"

namespace Gloom {

using Vector2f = linalg::aliases::float2;
using Vector3f = linalg::aliases::float3;
using Vector4f = linalg::aliases::float4;
using Vector2i = linalg::aliases::int2;
using Vector3i = linalg::aliases::int3;
using Vector4i = linalg::aliases::int4;
using Vector2u = linalg::aliases::uint2;
using Vector3u = linalg::aliases::uint3;
using Vector4u = linalg::aliases::uint4;

using Matrix4f = linalg::aliases::float4x4;

template <typename T> using Vector2 = linalg::vec<T, 2>;
template <typename T> using Vector3 = linalg::vec<T, 3>;
template <typename T> using Vector4 = linalg::vec<T, 4>;

} // namespace Gloom

#endif // MATHEMATICS_TYPES_H
