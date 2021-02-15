#include "Tile.h"

#include "Config.h"
#include "TextureManager.h"
#include "Util.h"

Tile::Tile() :m_cost(0.0f)
{
	setWidth(Config::TILE_SIZE);
	setHeight(Config::TILE_SIZE);
}
Tile::~Tile()
= default;

void Tile::draw()
{
	Util::DrawRect(getTransform()->position, getWidth(), getHeight());
}

void Tile::update()
{
}

void Tile::clean()
{
}

Tile* Tile::getNeighbourTile(NeighbourTile position)
{
return m_neighbours[position];
}

void Tile::setNeighbourTile(NeighbourTile position, Tile* tile)
{
	m_neighbours[position] = tile;
}

float Tile::getTileCost() const
{
	return m_cost;
}

void Tile::setTileCost(const float cost)
{
	m_cost = cost;

	// format string to 1 decimal place
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << cost;
	const std::string cost_string = stream.str();

	m_costLabel->setText(cost_string);
}
