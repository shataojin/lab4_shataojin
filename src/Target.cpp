#include "Target.h"


#include "SoundManager.h"
#include "TextureManager.h"


Target::Target()
{
	TextureManager::Instance()->load("../Assets/textures/Circle.png", "circle");

	const auto size = TextureManager::Instance()->getTextureSize("circle");
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = glm::vec2(100.0f, 100.0f);
	getRigidBody()->velocity = glm::vec2(0, 0);
	getRigidBody()->isColliding = false;

	setType(TARGET);

	SoundManager::Instance().load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);
}

Target::~Target()
= default;

void Target::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the target
	TextureManager::Instance()->draw("circle", x, y, 0, 255, true);
}

void Target::update()
{
	m_move();
	m_checkBounds();
}

void Target::clean()
{
}

glm::vec2 Target::getGridPosition() const
{
	return m_gridPosition;
}

void Target::setGridPosition(const float col, const float row)
{
	m_gridPosition = glm::vec2(col, row);
}

void Target::m_move()
{
	getTransform()->position = getTransform()->position + getRigidBody()->velocity * 5.0f;
}

void Target::m_checkBounds()
{
}

void Target::m_reset()
{
}
