#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofPoint point_left = ofPoint(ofGetWidth() / 6 * 1, ofGetHeight() / 2);
	ofPoint point_right = ofPoint(ofGetWidth() / 6 * 5, ofGetHeight() / 2);
	ofPoint point_top = ofPoint(ofGetWidth() / 2, ofGetHeight() / 6 * 1);
	ofPoint point_bottom = ofPoint(ofGetWidth() / 2, ofGetHeight() / 6 * 5);

	float radius = 100;
	ofColor color;
	for (int deg = 0; deg < 360; deg += 15) {

		color.setHsb(ofMap(deg % 360, 0, 359, 0, 255), 239, 239);
		ofSetColor(color);

		int deg_left = deg + ofGetFrameNum() * 0.5;
		int deg_top = deg_left + 90;
		int deg_right = deg_top + 90;
		int deg_bottom = deg_right + 90;

		ofPoint mini_point_left = point_left + ofPoint(radius * cos(deg_left * DEG_TO_RAD), radius * sin(deg_left * DEG_TO_RAD));
		ofPoint mini_point_top = point_top + ofPoint(radius * cos(deg_top * DEG_TO_RAD), radius * sin(deg_top * DEG_TO_RAD));
		ofPoint mini_point_right = point_right + ofPoint(radius * cos(deg_right * DEG_TO_RAD), radius * sin(deg_right * DEG_TO_RAD));
		ofPoint mini_point_bottom = point_bottom + ofPoint(radius * cos(deg_bottom * DEG_TO_RAD), radius * sin(deg_bottom * DEG_TO_RAD));

		ofDrawCircle(mini_point_left, 3);
		ofDrawCircle(mini_point_top, 3);
		ofDrawCircle(mini_point_right, 3);
		ofDrawCircle(mini_point_bottom, 3);

		ofDrawLine(mini_point_left, mini_point_top);
		ofDrawLine(mini_point_top, mini_point_right);
		ofDrawLine(mini_point_right, mini_point_bottom);
		ofDrawLine(mini_point_bottom, mini_point_left);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}