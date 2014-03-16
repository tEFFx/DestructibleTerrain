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

private:
	Terrain(void);
	~Terrain(void);

	sf::RenderTexture mRenderTexture;
	sf::RectangleShape mTempTerrain;
	sf::Texture mTerrain;
	Holes mHoles;
	bool mChanged;
};

