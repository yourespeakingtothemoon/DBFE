#pragma once
#include "Vector2.h"
#include "Mat2x2.h"
#include "Mat3x3.h"
#include "Math/mathUtils.h"

namespace dbf
{
	struct Transform
	{
		Vector2 position;
		float rotation{ 0 };
		Vector2 scale{ 1 };
		Mat3x3 matrix;


		void Update()
		{
			Mat3x3 mxScale = Mat3x3::createScale(scale);
			Mat3x3 mxRotate = Mat3x3::createRotate(math::DegToRad(rotation));
			Mat3x3 mxTranslate = Mat3x3::createTranslation(position);
			matrix = { mxTranslate * mxRotate * mxScale };   //TRS!=SRT
		}

		void Update(const Mat3x3& parent)
		{
			Mat3x3 mxScale = Mat3x3::createScale(scale);
			Mat3x3 mxRotate = Mat3x3::createRotate(math::DegToRad(rotation));
			Mat3x3 mxTranslate = Mat3x3::createTranslation(position);
			matrix = { mxTranslate * mxRotate * mxScale };   //TRS!=SRT
			matrix= parent * matrix;
		}


		operator Mat3x3 () const
		{
			Mat3x3 mxScale = Mat3x3::createScale(scale);
			Mat3x3 mxRotate = Mat3x3::createRotate(math::DegToRad(rotation));
			Mat3x3 mxTranslate = Mat3x3::createTranslation(position);
			
			return { mxScale * mxRotate *mxTranslate};
		}
		
	};
}
