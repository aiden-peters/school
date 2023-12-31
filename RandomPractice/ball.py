from graphics import *
import time
import random
class bouncyBall:
    def __init__(self, x, y, vx, vy):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.c = Circle(Point(x,y), 10)

 
def main():
    win = GraphWin("DVD", length, height, autoflush = False)
    r = 10
    grav  = 0.2
    frameRate = 0.025
    balls = []
    while(True):
        lastPoint = Point(0,0)
        addBall = win.checkMouse();
        if(addBall != None and addBall != lastPoint):
            balls.append(bouncyBall(addBall.x, addBall.y, 2, 2))
            lastPoint = addBall
        time.sleep(frameRate)
        for i in balls:
            i.c.undraw()
            i.c.move(i.vx, i.vy)
            i.c.draw(win)
            i.x += i.vx
            i.y += i.vy
            i.vy = i.vy + grav
            if(i.x+r >= length or i.x-r <= 0):
                i.vx = -1.01*i.vx
                if(i.x-r<=10 and i.vx<0):
                    i.vx*=-1
                if(i.vx<-20):
                    i.vx = -20
                if(i.vx>10):
                    i.vx = 20
                i.c.setFill(color_rgb(random.randint(0,255), random.randint(0,255), random.randint(0,255)))
            if(i.y+r >= height or i.y-r <= 0):
                i.vy = -1.01*i.vy
                if(i.y-r<=10 and i.vy<0):
                    i.vy*=-1
                if(i.y+r>=height and i.vy>0):
                    i.vy*=-1
                if(i.vy<-20):
                    i.vy = -20
                if(i.vy>20):
                    i.vy = 20
                i.c.setFill(color_rgb(random.randint(0,255), random.randint(0,255), random.randint(0,255)))
    
height = 760
length = 1024
main()
