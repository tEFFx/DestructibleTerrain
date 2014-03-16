#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

typedef std::vector<sf::CircleShape> Holes;

class Terrain
{
public:
	static Terrain& getInstance();

	void draw(sf::RenderWindow& window);
	void createHole(sf::Vector2f pos, float radius);
	sf::Image* getTerrainImage();

private:
	Terrain(void);
	~Terrain(void);
	void load();

	sf::RenderTexture mRenderTexture;
	sf::Sprite mTerrainSpr;
	sf::Texture mTerrain;
	Holes mHoles;
	bool mChanged;
};

