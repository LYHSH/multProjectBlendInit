#pragma once
/************************************************************************/
/* project name:多视频融合-融合参数初始化软件
/* file describe:
/* author:hui
/* date:2019.01.31
/************************************************************************/
#include "ofMain.h"
#include "projectBlendIniter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		int blendNums;
		//UI
		bool bShowGui;
		ofxImGui::Gui gui;
		void showSettingWindow(bool & _bOpen);

		int editorIndex;
		projectBlendIniter initer;

		bool showInitGui;
};
