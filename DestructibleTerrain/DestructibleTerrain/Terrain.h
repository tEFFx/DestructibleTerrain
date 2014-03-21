#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

typedef std::vector<sf::CircleShape*> Holes;

class Terrain
{
public:
	static Terrain& getInstance();

	void draw(sf::RenderWindow& window);
	void createHole(sf::Vector2f pos, float radius);
	sf::Image& getTerrainImage();
	void reset();

private:
	Terrain(void);
	Terrain(Terrain const&);
	void operator=(Terrain const&);

	void load();

	sf::RenderTexture mRenderTexture;
	sf::Sprite mTerrainSpr;
	sf::Image mTerrainImg;
	sf::Texture mTerrain;
	Holes mHoles;
	bool mChanged;
};

