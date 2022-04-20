#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	ofImage m_islandImage;
	ofVec2f m_islandPos;
	float m_islandAngle;

	ofImage m_seagullImage;
	ofVec2f m_seagullPos;
	float m_seagullAngle;

	ofImage m_chickImage;
	ofVec2f m_chickPos;
	float m_chickAngle;

	ofImage m_kiteImage;
	ofVec2f m_kitePos;
	float m_kiteAngle;
	ofVec2f m_targetkitePos;

	bool click;
	ofVec2f m_mousePos;
	float lerp(float start, float end, float percent);

	ofImage m_tailImage;
	ofVec2f m_targetTailPos;
	ofVec2f m_tailPos;
	float m_tailAngle;

	ofVec2f m_tailPos2;
	float m_tailAngle2;

	ofVec2f m_tailPos3;
	float m_tailAngle3;

	ofSoundPlayer   Seagull;
	ofSoundPlayer   Ocean;

	ofVec2f trail(ofVec2f target, ofVec2f currPos, float change);
	void drawLine(float xStart, float yStart, float xEnd, float yEnd); 

	void keyPressed(int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
};
