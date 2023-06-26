-- Thrifty Threads Main File

-- Setting the Screen Resolution
love.window.setMode(800, 600)

-- Include Libraries
local vec = require "libs/hump/vector"
local anim8 = require "libs/anim8/anim8"

-- Variables
local player = {
  position = vec(400, 300),
  velocity = vec(100, 0),
  size = vec(10, 10)
}

local shopSignPosition = vec(400, 150)
local shopSignSize = vec(40, 30)

-- Load Images
-- Shop Sign
local shopSignImage = love.graphics.newImage("assets/images/shopSign.png")

-- Player
local playerImage = love.graphics.newImage("assets/images/player.png")

-- Animations
local playerAnimation = anim8.newAnimation(playerImage, 0.2)

-- Functions

-- Game Update
function love.update(dt)
  playerAnimation:update(dt)
  player.position = player.position + (player.velocity * dt)

  -- Handle Sign Collisions
  if player.position.x + player.size.x > shopSignPosition.x and 
     player.position.x < shopSignPosition.x + shopSignSize.x and 
     player.position.y + player.size.y > shopSignPosition.y and 
     player.position.y < shopSignPosition.y + shopSignSize.y then
    -- Move Player to the Left
    player.velocity.x = -player.velocity.x
  end
end

-- Game Draw
function love.draw()
  -- Draw the Background
  love.graphics.setBackgroundColor(255, 255, 255)

  -- Draw Player
  love.graphics.draw(playerAnimation.image, player.position.x, 
    player.position.y, 0, player.size.x/playerAnimation.image:getWidth(),
    player.size.y/playerAnimation.image:getHeight())

  -- Draw Shop Sign
  love.graphics.draw(shopSignImage, shopSignPosition.x,
    shopSignPosition.y, 0, shopSignSize.x/shopSignImage:getWidth(),
    shopSignSize.y/shopSignImage:getHeight())
end