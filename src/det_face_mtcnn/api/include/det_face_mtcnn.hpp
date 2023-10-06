///////////////////////////////////////////////////////////////////////////////////////
///  Copyright (C) 2017, TAL AILab Corporation, all rights reserved.
///
///  @file: det_face_mtcnn.hpp
///  @brief ���ͼ���е�����
///  @details
///
///
///  @version 2.0.0.2
///  @author Ye Gensheng
///  @date 2018-04-20
///  
///  @see ʹ�òο���demo.cpp
///
///////////////////////////////////////////////////////////////////////////////////////

#ifndef __FACETHINK_API_DET_FACE_MTCNN_HPP__
#define __FACETHINK_API_DET_FACE_MTCNN_HPP__

#include <string>
#include <math.h>
#include <opencv2/opencv.hpp>

#ifdef WIN32
#ifdef DLL_EXPORTS
#define EXPORT_CLASS   __declspec(dllexport)
#define EXPORT_API  extern "C" __declspec(dllexport)
#define EXPORT_CLASS_API

#else
#define EXPORT_CLASS   __declspec(dllimport )
#define EXPORT_API  extern "C" __declspec(dllimport )
#endif
#else
#define EXPORT_CLASS
#define EXPORT_API  extern "C" __attribute__((visibility("default")))   
#define EXPORT_CLASS_API __attribute__((visibility("default")))   
#endif


namespace facethink {

    class EXPORT_CLASS FaceDetectionMTCNN {
    public:

		EXPORT_CLASS_API explicit FaceDetectionMTCNN(void);
		EXPORT_CLASS_API virtual ~FaceDetectionMTCNN(void);

		/*!
		\brief SDK��ʼ�����������������κ�����SDK����֮ǰ���á�
		@param [in] det1_model_prototxt ָ��SDK��Ӧ��ģ��1�����ļ�·����
		@param [in] det1_model_binary ָ��SDK��Ӧ��ģ��1�����ļ�·����
		@param [in] det2_model_prototxt ָ��SDK��Ӧ��ģ��2�����ļ�·����
		@param [in] det2_model_binary ָ��SDK��Ӧ��ģ��2�����ļ�·����
		@param [in] det3_model_prototxt ָ��SDK��Ӧ��ģ��3�����ļ�·����
		@param [in] det3_model_binary ָ��SDK��Ӧ��ģ��3�����ļ�·����
		@param [in] config_file ָ��SDK��Ӧ�Ĳ��������ļ�·����
		@return
		@remarks ��ʼ��������Ҫ��ȡģ�͵��ļ�����Ҫһ��ʱ��ȴ���
		*/
		EXPORT_CLASS_API static FaceDetectionMTCNN* create(
			const std::string& det1_model_prototxt,
			const std::string& det1_model_binary,
			const std::string& det2_model_prototxt,
			const std::string& det2_model_binary,
			const std::string& det3_model_prototxt,
			const std::string& det3_model_binary,
			const std::string& config_file);


		/*!
		\brief SDK��ʼ�����������������κ�����SDK����֮ǰ���ã�create�����غ�����
		@param [in] det1_model_file ָ��SDK��Ӧ��ģ���ļ�1·����
		@param [in] det2_model_file ָ��SDK��Ӧ��ģ���ļ�2·����
		@param [in] det3_model_file ָ��SDK��Ӧ��ģ���ļ�3·����
		@param [in] config_file ָ��SDK��Ӧ�Ĳ��������ļ�·��,�����config.ini�ļ���
		@return
		@remarks ��ʼ��������Ҫ��ȡģ�͵��ļ�����Ҫһ��ʱ��ȴ���
		*/
		EXPORT_CLASS_API static FaceDetectionMTCNN* create(
			const std::string& det1_model_file,
			const std::string& det2_model_file,
			const std::string& det3_model_file,
			const std::string& config_file);


		/// \brief �������ͼ���е����������ʱͼ���СĬ��ѹ��50%����ͨ�������ļ��޸Ĳ�������
		/// @param [in] img �����ͼ�����ݣ�֧�����������ָ�ʽ:
		/// - 1.�Ҷ�ͼ��imgΪһά���飬ÿ��Ԫ�أ��ֽڣ���ʾһ�����ص�ĻҶ�ֵ(��ΧΪ0-255����
		/// - 2.BGRͼ��imgΪһά���飬ÿ��Ԫ�أ��ֽڣ���ʾһ�����ص�ĵ�ͨ��ȡֵ����������Ԫ�ر�ʾһ�����ص����ͨ��ȡֵ��˳��ΪBGR��
		/// @param [out] rectangles ����SDK��⵽���������ο�������ÿ��Ԫ�ر�ʾһ���˵ļ������
		/// @param [out] confidence ����SDK��⵽�����������Ŷȣ�����ÿ��Ԫ����rectangles�е�Ԫ�ض�Ӧ��
		/// @return
		EXPORT_CLASS_API virtual void detection_SCALE(const cv::Mat& img, std::vector<cv::Rect>& rectangles, std::vector<float>& confidence) = 0;


		/// \brief �������ͼ���е����������ʱͼ���СĬ��ѹ��50%����ͨ�������ļ��޸Ĳ�������
		/// @param [in] img �����ͼ�����ݣ�֧�����������ָ�ʽ:
		/// - 1.�Ҷ�ͼ��imgΪһά���飬ÿ��Ԫ�أ��ֽڣ���ʾһ�����ص�ĻҶ�ֵ(��ΧΪ0-255����
		/// - 2.BGRͼ��imgΪһά���飬ÿ��Ԫ�أ��ֽڣ���ʾһ�����ص�ĵ�ͨ��ȡֵ����������Ԫ�ر�ʾһ�����ص����ͨ��ȡֵ��˳��ΪBGR��
		/// @param [out] rectangles ����SDK��⵽���������ο�������ÿ��Ԫ�ر�ʾһ���˵ļ������
		/// @param [out] confidence ����SDK��⵽�����������Ŷȣ�����ÿ��Ԫ����rectangles�е�Ԫ�ض�Ӧ��
		/// @param [out] alignment ����SDK��⵽��������5���㣨������+�����+�Ǽ⣩��
		/// @return
		EXPORT_CLASS_API virtual void detection_SCALE(const cv::Mat& img, std::vector<cv::Rect>& rectangles, std::vector<float>& confidence, std::vector<std::vector<cv::Point>>& alignment) = 0;
		
    };

}

#endif
