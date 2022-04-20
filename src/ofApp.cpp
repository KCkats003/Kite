#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	//window 
	ofSetBackgroundColor(60, 150, 210);
	ofSetWindowShape(1500, 900);

	//anchor point 
	ofSetRectMode(OF_RECTMODE_CENTER);

	//mouse position 
	m_mousePos.set(0.0f, 0.0f);
	click = false;

	//sun
	m_islandImage.load("Island.png");
	m_islandPos.set(ofGetWindowWidth() / 2.0f, ofGetWindowHeight() / 2.0f);
	m_islandAngle = 0.0f;


	//seagulls 
	m_seagullImage.load("Seagull.png");
	m_seagullPos.set(0.0f, 100.0f);
	m_seagullAngle = 0.0f;

	//chick 
	m_chickImage.load("Chick.png");
	m_chickPos.set(0.0f, 50.0f);

	//the kite 
	m_kiteImage.load("Kite.png");
	m_kitePos.set(ofGetWindowWidth() / 2.0f, ofGetWindowHeight() / 2.0f);
	m_targetkitePos.set(m_kitePos.x, m_kitePos.y);
	m_kiteAngle = 0.0f;

	//Tail 1
	m_tailImage.load("Tail.png");
	m_tailPos.set(m_kitePos.x - 600, m_kitePos.y);
	m_tailAngle = 0.0f;
	m_targetTailPos.set(m_tailPos.x, m_tailPos.y);;

	//Tail 2 
	m_tailPos2 = m_tailPos;
	m_tailPos2.x = m_tailPos2.x - 100;
	m_tailAngle2 = 0.0f;

	//Tail 3
	m_tailPos3 = m_tailPos;
	m_tailPos3.x = m_tailPos3.x - 300;
	m_tailAngle3 = 0.0f;

	Seagull.load("Seagull.mp3");
	Seagull.play();

	Ocean.load("Ocean.mp3");
	Ocean.play();

}

//--------------------------------------------------------------
void ofApp::update() {
	// sun 
	m_islandPos.set(ofGetWindowWidth() / 2.0f, ofGetWindowHeight() / 2.0f);

	//Making the seagulls Spin 
	m_seagullAngle += 5;

	//Getting Mouse position 
	m_mousePos.set((float)ofGetMouseX(), (float)ofGetMouseY());

	//kite Face Mouse
	ofVec2f vecToMouse = m_mousePos - m_kitePos;
	m_kiteAngle = ofRadToDeg(atan2(vecToMouse.y, vecToMouse.x));

	ofRotateDeg(m_kitePos.x);
	ofRotateDeg(m_kitePos.y);

	//kite moves towards the mouse 
	m_kitePos = trail(m_kitePos, m_targetkitePos, 0.02f);

	//Tail faces kite 
	ofVec2f vecTokite = m_kitePos - m_tailPos;
	m_tailAngle = ofRadToDeg(atan2(vecTokite.y, vecTokite.x));
	m_tailAngle = lerp(m_tailAngle, m_kiteAngle, 0.02f);

	//Tail 1 Moves towards the kite 
	m_targetTailPos = m_kitePos;
	m_tailPos = trail(m_tailPos, m_targetTailPos, 0.02f);

}


ofVec2f ofApp::trail(ofVec2f currPos, ofVec2f target, float change) {
	ofVec2f nextpos = currPos;
	nextpos.x = lerp(currPos.x, target.x, change);
	nextpos.y = lerp(currPos.y, target.y, change);

	return nextpos;
}

void ofApp::drawLine( float xStart, float yStart, float xEnd, float yEnd) {
	ofSetColor(ofColor(116, 75, 29));
	ofSetLineWidth(5.0);
	ofDrawLine(xStart, yStart, xEnd, yEnd);
	ofSetColor(ofColor(255, 255, 255));
}

void ofApp::draw() {


	if (click == true) {
		ofDrawCircle(m_mousePos.x, m_mousePos.y, 20);
	}

	//Draw the Island
	ofPushMatrix();
		ofTranslate(m_islandPos);
		ofScale(0.5f, 0.5f);
		ofRotateDeg(m_islandAngle);
		m_islandImage.draw(0, 0);
		ofPopMatrix();

	//White Kite Line 
	ofSetLineWidth(5.0);
	ofDrawLine(m_kitePos.x, m_kitePos.y, m_islandPos.x, m_islandPos.y);

	//for the little seagull
	ofPushMatrix();
		ofTranslate(m_islandPos);

		ofRotateDeg(m_seagullAngle*0.3);
		ofTranslate(m_seagullPos * 2);
		ofScale(0.4f, 0.4f);
	m_seagullImage.draw(0, 0);
	ofPopMatrix();

	//for the little seagull 
	ofPushMatrix();
		ofTranslate(m_islandPos);

		ofRotateDeg(m_seagullAngle * 0.5);
		ofTranslate(m_seagullPos * 2.5);
		ofScale(0.3f, 0.3f);
		m_seagullImage.draw(0, 0);
	ofPopMatrix();
	
	//for the little seagull 
	ofPushMatrix();
		ofTranslate(m_islandPos);

		ofRotateDeg(m_seagullAngle * 0.1);
		ofTranslate(m_seagullPos * 3.5);
		ofScale(0.5f, 0.5f);
	m_seagullImage.draw(0, 0);

			// little chick 
			ofRotateDeg(m_seagullAngle * 0.1);
				ofTranslate(m_chickPos * 4);
				ofScale(0.3f, 0.3f);
				m_chickImage.draw(0, 0);
	ofPopMatrix();



	//for the little seagull 
	ofPushMatrix();
		ofTranslate(m_islandPos);
		ofRotateDeg(m_seagullAngle * 0.05);
		ofTranslate(m_seagullPos * 5);
		ofScale(0.55f, 0.55f);
	m_seagullImage.draw(0, 0);

			// little chick 
			ofRotateDeg(m_seagullAngle * 0.1);
				ofTranslate(m_chickPos * 5);
				ofScale(0.5f, 0.5f);
				m_chickImage.draw(0, 0);
			ofPopMatrix();

	// tail 1
	ofPushMatrix();
		ofTranslate(m_tailPos);
		ofRotateDeg(m_tailAngle);
		ofScale(0.3f, 0.3f);
	m_tailImage.draw(0, 0);

	ofPopMatrix();

	//draw line 
	ofPushMatrix();
	drawLine(m_kitePos.x, m_kitePos.y, m_tailPos.x, m_tailPos.y);
	ofPopMatrix();

	// tail 2
	ofPushMatrix();
	    m_tailPos2 = trail(m_tailPos2, m_tailPos, 0.02f);
		m_tailAngle2 = lerp(m_tailAngle2, m_tailAngle, 0.02f);
		ofTranslate(m_tailPos2);
		ofRotateDeg(m_tailAngle2);
		ofScale(0.3f, 0.3f);
		m_tailImage.draw(0, 0);
	ofPopMatrix();

	//draw line
	ofPushMatrix();
		drawLine(m_tailPos.x, m_tailPos.y, m_tailPos2.x, m_tailPos2.y);
	ofPopMatrix();

	// tail 3
	ofPushMatrix();
		m_tailPos3 = trail(m_tailPos3, m_tailPos2, 0.02f);
		m_tailAngle3 = lerp(m_tailAngle3, m_tailAngle2, 0.02f);
		ofTranslate(m_tailPos3);
		ofRotateDeg(m_tailAngle3);
		ofScale(0.3f, 0.3f);
		m_tailImage.draw(0, 0);
	ofPopMatrix();

	//draw line 
	ofPushMatrix();
		drawLine(m_tailPos2.x, m_tailPos2.y, m_tailPos3.x, m_tailPos3.y);
	ofPopMatrix();

	//drawingg the little kite
	ofPushMatrix();
		ofTranslate(m_kitePos);
		ofRotateDeg(m_kiteAngle);
		ofScale(0.3f, 0.3f);
		m_kiteImage.draw(0, 0);
	ofPopMatrix();

}



void ofApp::mouseDragged(int x, int y, int button) {
	m_targetkitePos.set((float)x, (float)y);
	click = true;
}

void ofApp::mousePressed(int x, int y, int button) {
	click = true;
	m_targetkitePos.set((float)x, (float)y);
	ofDrawCircle(x, y, 100);
	ofDrawCircle(100, 100, 100);
}

float ofApp::lerp(float start, float end, float percent) {
	return (start + percent * (end - start));
}

void ofApp::keyPressed(int key) {
	Seagull.play();
	Ocean.play();
}

void ofApp::mouseReleased(int x, int y, int button) {
	click = false;
}

