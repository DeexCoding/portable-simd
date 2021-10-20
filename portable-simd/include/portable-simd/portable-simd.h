#ifndef PORTABLE_SIMD_H
#define PORTABLE_SIMD_H

//Checking for architecture
#if defined(__x86_64__) || defined(_M_X64)
#include <immintrin.h>
#include <xmmintrin.h>
#define PORTABLE_SIMD_ARCH_x86_64
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
#include <immintrin.h>
#include <xmmintrin.h>
#define PORTABLE_SIMD_ARCH_x86_32
#elif defined(__ARM_ARCH_2__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM2
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM3
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM4T
#elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM5
#elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM6T2
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM6
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM7
#elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM7A
#elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM7R
#elif defined(__ARM_ARCH_7M__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM7M
#elif defined(__ARM_ARCH_7S__)
#include <arm_neon.h>
#define PORTABLE_SIMD_ARCH_ARM7S
#elif defined(__aarch64__) || defined(_M_ARM64)
#include <arm64_neon.h>
#define PORTABLE_SIMD_ARCH_ARM64
#elif defined(mips) || defined(__mips__) || defined(__mips)
#define PORTABLE_SIMD_ARCH_MIPS
#elif defined(__sh__)
#define PORTABLE_SIMD_ARCH_SUPERH
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
#define PORTABLE_SIMD_ARCH_POWERPC
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
#define PORTABLE_SIMD_ARCH_POWERPC64
#elif defined(__sparc__) || defined(__sparc)
#define PORTABLE_SIMD_ARCH_SPARC
#elif defined(__m68k__)
#define PORTABLE_SIMD_ARCH_M68K
#else
#include <math.h>
#define PORTABLE_SIMD_ARCH_UNKNOWN
#endif

#ifdef __cplusplus
extern "C" 
{
#endif

//SIMD type definitions
#ifdef PORTABLE_SIMD_ARCH_x86_64
typedef __m128 simd4f;
#elif defined(PORTABLE_SIMD_ARCH_x86_32)
typedef __m128 simd4f;
#else

typedef struct
{
	float a;
	float b;
	float c;
	float d;

} simd4f;

#endif

//Creation functions
simd4f Create4f(float a, float b, float c, float d)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_set_ps(a, b, c, d);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_set_ps(a, b, c, d);

#else

	simd4f ret;
	ret.a = a;
	ret.b = b;
	ret.c = c;
	ret.d = d;
	
	return ret;

#endif
}

simd4f Add4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_add_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_add_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_ARM2)

#else

	simd4f ret;
	ret.a = a.a + b.a;
	ret.b = a.b + b.b;
	ret.c = a.c + b.c;
	ret.d = a.d + b.d;

	return ret;

#endif
}

simd4f Substract4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_sub_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_sub_ps(a, b);

#else

	simd4f ret;
	ret.a = a.a - b.a;
	ret.b = a.b - b.b;
	ret.c = a.c - b.c;
	ret.d = a.d - b.d;

	return ret;

#endif
}

simd4f Multiply4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_mul_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_mul_ps(a, b);

#else

	simd4f ret;
	ret.a = a.a * b.a;
	ret.b = a.b * b.b;
	ret.c = a.c * b.c;
	ret.d = a.d * b.d;

	return ret;

#endif
}

simd4f Divide4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_div_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_div_ps(a, b);

#else

	simd4f ret;
	ret.a = a.a / b.a;
	ret.b = a.b / b.b;
	ret.c = a.c / b.c;
	ret.d = a.d / b.d;

	return ret;

#endif
}

simd4f SquareRoot4f(simd4f a)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_sqrt_ps(a);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_sqrt_ps(a);

#else

	simd4f ret;
	ret.a = sqrt(a.a);
	ret.b = sqrt(a.b);
	ret.c = sqrt(a.c);
	ret.d = sqrt(a.d);

	return ret;

#endif
}

simd4f InverseSquareRoot4f(simd4f a)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_rsqrt_ps(a);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_rsqrt_ps(a);

#else

	simd4f ret;
	ret.a = 1.0f / sqrt(a.a);
	ret.b = 1.0f / sqrt(a.b);
	ret.c = 1.0f / sqrt(a.c);
	ret.d = 1.0f / sqrt(a.d);

	return ret;

#endif
}

simd4f Round4f(simd4f a)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_round_ps(a, 0);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_round_ps(a, 0);

#else

	simd4f ret;
	ret.a = round(a.a);
	ret.b = round(a.b);
	ret.c = round(a.c);
	ret.d = round(a.d);

	return ret;

#endif
}

simd4f Inverse4f(simd4f a)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_rcp_ps(a);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_rcp_ps(a);

#else

	simd4f ret;
	ret.a = 1.0f / a.a;
	ret.b = 1.0f / a.b;
	ret.c = 1.0f / a.c;
	ret.d = 1.0f / a.d;

	return ret;

#endif
}

simd4f Max4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_max_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)
	
	return _mm_max_ps(a, b);

#else

	simd4f ret;

	if (a.a > b.a)
	{
		ret.a = a.a;
	}
	else
	{
		ret.a = b.a;
	}

	if (a.b > b.b)
	{
		ret.b = a.b;
	}
	else
	{
		ret.b = b.b;
	}

	if (a.c > b.c)
	{
		ret.c = a.c;
	}
	else
	{
		ret.c = b.c;
	}

	if (a.d > b.d)
	{
		ret.d = a.d;
	}
	else
	{
		ret.d = b.d;
	}

	return ret;

#endif
}

simd4f Min4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_min_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_min_ps(a, b);

#else

	simd4f ret;

	if (a.a < b.a)
	{
		ret.a = a.a;
	}
	else
	{
		ret.a = b.a;
	}

	if (a.b < b.b)
	{
		ret.b = a.b;
	}
	else
	{
		ret.b = b.b;
	}

	if (a.c < b.c)
	{
		ret.c = a.c;
	}
	else
	{
		ret.c = b.c;
	}

	if (a.d < b.d)
	{
		ret.d = a.d;
	}
	else
	{
		ret.d = b.d;
	}

	return ret;

#endif
}

simd4f And4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_and_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_and_ps(a, b);

#else

	simd4f ret;
	ret.a = a.a & b.a;
	ret.b = a.b & b.b;
	ret.c = a.c & b.c;
	ret.d = a.d & b.d;

	return ret;

#endif
}

simd4f Or4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_and_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_and_ps(a, b);

#else

	simd4f ret;
	ret.a = a.a | b.a;
	ret.b = a.b | b.b;
	ret.c = a.c | b.c;
	ret.d = a.d | b.d;

	return ret;

#endif
}

simd4f ExclusiveOr4f(simd4f a, simd4f b)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64

	return _mm_xor_ps(a, b);

#elif defined(PORTABLE_SIMD_ARCH_x86_32)

	return _mm_xor_ps(a, b);

#else

	simd4f ret;
	ret.a = a.a ^ b.a;
	ret.b = a.b ^ b.b;
	ret.c = a.c ^ b.c;
	ret.d = a.d ^ b.d;

	return ret;

#endif
}

void Unpack4f(simd4f x, float* a, float* b, float* c, float* d)
{
#ifdef PORTABLE_SIMD_ARCH_x86_64 || defined(PORTABLE_SIMD_ARCH_x86_32)
#if defined(_WIN32)

	*a = (float)x.m128_f32[3];
	*b = (float)x.m128_f32[2];
	*c = (float)x.m128_f32[1];
	*d = (float)x.m128_f32[0];

#elif defined(__linux__)

	*a = (float)x[3];
	*b = (float)x[2];
	*c = (float)x[1];
	*d = (float)x[0];

#endif


#else

	*a = x.a;
	*b = x.b;
	*c = x.c;
	*d = x.d;

#endif
}

#ifdef __cplusplus
}
#endif

#endif