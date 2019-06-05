#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bShowGui = true;

	blendNums = 0;

	gui.setup();


	initer.setup();
	editorIndex = -1;
	showInitGui = false;

	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
	initer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(114, 144, 154);
	gui.begin();
	showSettingWindow(bShowGui);
	gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::showSettingWindow(bool & _bOpen)
{
	if (_bOpen)
	{
		static bool no_titlebar = false;
		static bool no_scrollbar = false;
		static bool no_menu = false;
		static bool no_move = true;
		static bool no_resize = true;
		static bool no_collapse = false;
		static bool no_close = true;
		static bool no_nav = false;

		static bool m_open = true;

		ImGuiWindowFlags window_flags = 0;
		if (no_titlebar)  window_flags |= ImGuiWindowFlags_NoTitleBar;
		if (no_scrollbar) window_flags |= ImGuiWindowFlags_NoScrollbar;
		if (!no_menu)     window_flags |= ImGuiWindowFlags_MenuBar;
		if (no_move)      window_flags |= ImGuiWindowFlags_NoMove;
		if (no_resize)    window_flags |= ImGuiWindowFlags_NoResize;
		if (no_collapse)  window_flags |= ImGuiWindowFlags_NoCollapse;
		if (no_nav)       window_flags |= ImGuiWindowFlags_NoNav;
		if (no_close)     m_open = NULL; // Don't pass our bool* to Begin

		ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(400, 480), ImGuiCond_Always);
		
		ImGui::Begin("edgeblendsetting", &m_open, window_flags);

		ImGui::Text("Press 'h' show UI");
		ImGui::Text("FPS:%.3f", ofGetFrameRate());

		ImGui::Spacing();
		ImGui::SliderInt("blend nums:", &blendNums, 0, 9);

		
		ImGui::BeginChild("#colors", ImVec2(400, 120), true, ImGuiWindowFlags_HorizontalScrollbar);
		for (int i = 0; i < blendNums; i++)
		{
			if (!(i % 3))
			{
				ImGui::NewLine();
			}
			int index = i;
			string name = "blend mgr:" + ofToString(index);
			if (ImGui::RadioButton(name.c_str(), &editorIndex, index))
			{
 				initer.setDir("blend/blendMgr" + ofToString(i) + "/");
 				initer.setTitle("blend" + ofToString(i));

				showInitGui = true;

				ofxXmlSettings xml;
				xml.addValue("BLEND_NUMS", blendNums);
				xml.save("blend.xml");
			}
			ImGui::SameLine();
		}
		ImGui::EndChild();

		if (editorIndex != -1)
		{
			initer.showGui(showInitGui);

			if (!showInitGui)
			{
				editorIndex = -1;
			}
		}
		ImGui::End();
	}
}
