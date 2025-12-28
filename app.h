#include <algorithm>
#include <utility>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class BonusApp : public App
{
public:
	void draw() override;
private:
	void drawDashedLines();
    void drawOlympicRings();
    void drawCrossedRectangle();
	void drawCircleWithRedCross();
	void drawConcentricCircles();

	void drawDashedLine(float x, float y, float length, float a, float b);
	void drawAlternatingDashedLine(float x, float y, float length, float a, float b, float c, float d);
};

void prepareSettings(BonusApp::Settings* settings);