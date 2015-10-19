//
//  CameraManipulators.h
//  ModelViewer
//  Created by sqh on 2015-8-4.
//
#ifndef __CAMERA_MANIPULATOR_H__
#define __CAMERA_MANIPULATOR_H__

#include "YZModelCoreModule.h"
#include <osgGA/KeySwitchMatrixManipulator>
#include "ManipulatorType.h"
//#include "ModelViewerImpl.h"
#include "ZoomModel.h"
#include <osg/Camera>
#include "Pick.h"
#include <memory>
#include "ICameraManipulators.h"
#include "CameraAnimation.h"
//#include "FixedFramerateController.h"
//#include <osgGA/MultiTouchTrackballManipulator>
//#include "fireSelectionEvent.h"
//#include "DragSelectionManipulator.h"
//#include "DraggerManipulator.h"
//#include "MouseManipulatorContainer.h"
//#include "osgGA/FirstPersonManipulator"
//#include "CameraManipulatorPickBase.h"
//#include "BIMFirstPersonManipulator.h"

namespace bimWorld
{
	class BIMCameraManipulator;

	class YIZHU_EXPORT CameraManipulator :public YZModelCoreModule, public ICameraManipulators
	{
	public:
		CameraManipulator(YZModelCoreInternal* host);

		void init();

		///-------------------------------------------------------------------------------------------------
		/// <summary>	切换漫游器. </summary>
		///
		/// <remarks>	Sqh, 2015/5/6. </remarks>
		///
		/// <param name="emanip">	The emanip. </param>
		///-------------------------------------------------------------------------------------------------
		virtual void switchMatrixManipulator(ManipulatorType emanip) override;

		virtual bimWorld::ViewerMode getCameraManipulatorMode() override;

		virtual void enableFirstPersonControl() override;

		virtual void disableFirstPersonControl() override;

		////////////////////////////////////////////////////////视图模式//////////////////////////////////////////////////////////////////////////////////
		virtual void setViewerMode(ViewerMode viewerMode) override;

		virtual std::shared_ptr<bimWorld::IZoomModel> ZoomModel() override;

		virtual const bimWorld::ListenerSet& getListeners() const override;

		virtual void clearSelection() override;

		virtual void updateModelSize() override;

		virtual void setModelCenter(void* center) override;

		virtual void bindKeyUpEvent(bimWorld::KeySymbol key, bimWorld::CameraOperationTypes operation) override;

		virtual void bindKeyDownEvent(bimWorld::KeySymbol key, bimWorld::CameraOperationTypes operation) override;

		virtual void bindMouseEvent(bimWorld::MouseButtonMask mouse, bimWorld::CameraOperationTypes operation) override;

		virtual void unbindKeyUpEvent(bimWorld::KeySymbol key) override;

		virtual void unbindKeyDownEvent(bimWorld::KeySymbol key) override;

		virtual void unbindMouseEvent(bimWorld::MouseButtonMask mouse) override;

	//internal:

		virtual std::shared_ptr<bimWorld::CameraAnimation> CameraAnimation();

		virtual osg::Camera* getCamera();

		osgGA::CameraManipulator* getCameraManipulator();

		bimWorld::BIMCameraManipulator* getBIMCameraManip();

	protected:
		// <绘制: true，更新: false。在执行 Camera 动画之前，在绘制阶段还是在仅更新阶段。>
		bool origin_draw;

		osg::ref_ptr<osgGA::CameraManipulator> m_d, m_p;

		// <漫游器切换>
		osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> m_ptrKeySwitchMatrixManipulator;

		// BIMCameraManipulator mode.
		bimWorld::ViewerMode m_cameraManipulatorMode;

		std::shared_ptr<bimWorld::ZoomModel> m_zoomModel;

		// <视图监听器集合>
		bimWorld::ListenerSet m_modelViewerListeners;

		std::shared_ptr<bimWorld::CameraAnimation> m_cameraAnimation;

		bool m_isFirstPersonManipEnabled;
		float m_zoomForwardDelta;
	};
}

#endif // __CAMERA_MANIPULATOR_H__