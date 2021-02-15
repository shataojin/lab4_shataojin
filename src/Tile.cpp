#include "Tile.h"

#include "Config.h"
#include "Label.h"
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

}
void Tile::addLabels()
{

	auto offset = glm::vec2(Config::TILE_SIZE * 0.5f, Config::TILE_SIZE * 0.5f);

	m_costLabel = new Label("99.9", "Consolas", 12);
	m_costLabel->getTransform()->position = getTransform()->position + offset + glm::vec2(0.0f, -6.0f);
	getParent()->addChild(m_costLabel);
	m_costLabel->setEnabled(false);

	m_statusLabel = new Label("--", "Consolas", 12);
	m_statusLabel->getTransform()->position = getTransform()->position + offset + glm::vec2(0.0f, 6.0f);;
	getParent()->addChild(m_statusLabel);
	m_statusLabel->setEnabled(false);
}

void Tile::setLabelsEnabled(const bool state)
{
	m_costLabel->setEnabled(state);
	m_statusLabel->setEnabled(state);

}
