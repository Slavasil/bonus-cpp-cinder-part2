#include "app.h"
#include <print>

void prepareSettings(BonusApp::Settings* settings)
{
	settings->setMultiTouchEnabled(false);
}

void BonusApp::draw() // с setup не срослось :(
{
    gl::clear(Color::white());
    drawDashedLines();
    drawOlympicRings();
    drawCrossedRectangle();
    drawCircleWithRedCross();
    drawConcentricCircles();
}

void BonusApp::drawDashedLines()
{
    gl::color(1.0f, 0.0f, 0.0f);
    drawDashedLine(15.0f, 15.0f, 220.0f, 14.0f, 3.0f);
    gl::color(0.0f, 1.0f, 0.0f);
    drawDashedLine(15.0f, 35.0f, 220.0f, 3.0f, 3.0f);
    gl::color(0.0f, 0.0f, 1.0f);
    drawAlternatingDashedLine(15.0f, 55.0f, 220.0f, 14.0f, 3.0f, 3.0f, 3.0f);
}

void BonusApp::drawOlympicRings()
{
    const float radius = 40.0f;
    const float x = 15.0f;
    const float y = 80.0f;
    gl::color(0.0f, 0.0f, 1.0f);
    gl::drawStrokedCircle(vec2(x + radius, y + radius), radius, 5.0f, 45);
    gl::color(0.0f, 0.0f, 0.0f);
    gl::drawStrokedCircle(vec2(x + radius * 3 + 12.0f, y + radius), radius, 5.0f, 45);
    gl::color(1.0f, 0.0f, 0.0f);
    gl::drawStrokedCircle(vec2(x + radius * 5 + 12.0f * 2, y + radius), radius, 5.0f, 45);
    gl::color(1.0f, 1.0f, 0.0f);
    gl::drawStrokedCircle(vec2(x + radius * 2 + 12.0f * 0.5f, y + radius * 2), radius, 5.0f, 45);
    gl::color(10.f/255.f, 122.f/255.f, 15.f/255.f);
    gl::drawStrokedCircle(vec2(x + radius * 4 + 12.0f * 1.5f, y + radius * 2), radius, 5.0f, 45);
}

void BonusApp::drawCrossedRectangle()
{
    const float x = 300.0f;
    const float y = 15.0f;
    gl::color(0.0f, 0.0f, 0.0f);
    gl::drawStrokedRect(Rectf(x, y, x + 180.0f, y + 120.0f));
    gl::drawLine(vec2(x, y), vec2(x + 180.0f, y + 120.0f));
    gl::drawLine(vec2(x + 180.0f, y), vec2(x, y + 120.0f));
}


void BonusApp::drawCircleWithRedCross()
{
    const float x = 300.0f;
    const float y = 180.0f;
    const float radius = 55.0f;
    gl::drawStrokedCircle(vec2(x + radius, y + radius), radius, 1.2f, 45);
    gl::lineWidth(4.0f);
    gl::color(1.0f, 0.0f, 0.0f);
    gl::drawLine(vec2(x + radius, y), vec2(x + radius, y + radius * 2));
    gl::drawLine(vec2(x, y + radius), vec2(x + radius * 2, y + radius));
}

void BonusApp::drawConcentricCircles()
{
    const float x = 145.0f;
    const float y = 300.0f;
    const float minRadius = 6.0f;
    const int count = 10;
    const float step = 6.0f;
    gl::color(0.0f, 0.0f, 0.0f);
    float r = minRadius;
    for (int i = 0; i < count; ++i)
    {
        gl::drawStrokedCircle(vec2(x, y), r, 1.0f, 45);
        r += step;
    }
}

void BonusApp::drawDashedLine(float x, float y, float length, float a, float b)
{
    float end = x + length;
    while (x < end)
    {
        gl::drawSolidRect(Rectf(x, y, x + a, y + 4.0f));
        x += a + b;
    }
}

void BonusApp::drawAlternatingDashedLine(float x, float y, float length, float a, float b, float c, float d)
{
    float end = x + length;
    while (x < end)
    {
        gl::drawLine(vec2(x, y), vec2(x + a, y));
        x += a + b;
        if (x >= end) break;
        gl::drawLine(vec2(x, y), vec2(x + c, y));
        x += c + d;
    }
}
