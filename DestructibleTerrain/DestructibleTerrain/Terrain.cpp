#include "Terrain.h"


Terrain::Terrain(void)
{
	load();
}

Terrain& Terrain::getInstance()
{
	static Terrain instance;
	return instance;
}

void Terrain::load()
{
	mRenderTexture.create(1280, 720);
	sf::Texture* temp = new sf::Texture;
	temp->loadFromFile("terrain.png");
	mTerrainSpr.setTexture(*temp);
	mTerrainSpr.setPosition(0, 0);
	mChanged = true;
}

void Terrain::draw(sf::RenderWindow& window)
{
	if(mChanged == true)
	{
		mRenderTexture.clear(sf::Color::Color(255, 255, 255, 0));
		mRenderTexture.draw(mTerrainSpr);

		for(auto it = mHoles.begin();
			it != mHoles.end();
			it++)
		{
			mRenderTexture.draw(*(*it));
		}

		mRenderTexture.display();

		mTerrainImg = mRenderTexture.getTexture().copyToImage();
		mTerrainImg.createMaskFromColor(sf::Color::Blue);
		mTerrain.loadFromImage(mTerrainImg);

		std::cout << "UPDATE" << std::endl;

		mChanged = false;
	}

	window.draw(sf::Sprite(mTerrain));
}

void Terrain::createHole(sf::Vector2f pos, float radius)
{
	sf::CircleShape* temp = new sf::CircleShape;
	temp->setRadius(radius);
	temp->setOrigin(radius, radius);
	temp->setPosition(pos);
	temp->setFillColor(sf::Color::Blue);
	mHoles.push_back(temp);
	mChanged = true;
}

sf::Image& Terrain::getTerrainImage()
{
	return mTerrainImg;
}

void Terrain::reset()
{
	while(!mHoles.empty())
	{
		delete mHoles[mHoles.size() - 1];
		mHoles.pop_back();
	}
	mChanged = true;
}