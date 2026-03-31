from ursina import *
from ursina.prefabs.first_person_controller import FirstPersonController

app = Ursina()

window.color = color.rgb(200,200,200)

# mặt đất
ground = Entity(
    model='plane',
    scale=100,
    color=color.yellow,
    collider='box'
)

# ánh sáng
DirectionalLight().look_at(Vec3(1,-1,-1))
AmbientLight(color=color.rgba(100,100,100,0.5))

# player
player = FirstPersonController()
player.position = (0,2,0)

# camera nhìn xuống đất
camera.y = 2
camera.rotation_x = 20

app.run()