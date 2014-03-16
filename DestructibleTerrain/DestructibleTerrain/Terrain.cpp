#include "Terrain.h"


Terrain::Terrain(void)
{
	mRenderTexture.create(1280, 720);
	mTempTerrain.setSize(sf::Vector2f(1280, 500));
	mTempTerrain.setPosition(0, 220);
	mChanged = true;
}


Terrain::~Terrain(void)
{
}


Terrain& Terrain::getInstance()
{
	static Terrain instance;
	return instance;
}

void Terrain::draw(sf::RenderWindow& window)
{
	if(mChanged == true)
	{
		mRenderTexture.clear(sf::Color::Blue);
		mRenderTexture.draw(mTempTerrain);

		for(auto it = mHoles.begin();
			it != mHoles.end();
			it++)
		{
			mRenderTexture.draw((*it));
		}

		mRenderTexture.display();

		sf::Image temp = mRenderTexture.getTexture().copyToImage();
		temp.createMaskFromColor(sf::Color::Blue);
		mTerrain.loadFromImage(temp);

		mChanged = false;
	}

	window.draw(sf::Sprite(mTerrain));
}

void Terrain::createHole(sf::Vector2f pos, float radius)
{
	sf::CircleShape temp;
	temp.setRadius(radius);
	temp.setOrigin(radius, radius);
	temp.setPosition(pos);
	temp.setFillColor(sf::Color::Blue);
	mHoles.push_back(temp);
	mChanged = true;
}