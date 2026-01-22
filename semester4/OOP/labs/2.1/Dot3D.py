import math

class Dot3D:

    def __init__(self, x, y, z, label=None):
        self.x = x
        self.y = y
        self.z = z
        self.label = label

    def distance_to(self, other):
        distance = math.sqrt(((other.x - self.x)**2) + ((other.y - self.y)**2) + ((other.z - self.z)**2))
        return distance
    
    def add_vector(self, other):
        new_x = self.x + other.x
        new_y = self.y + other.y
        new_z = self.z + other.z
        return Dot3D(new_x, new_y, new_z, label="{}+{}".format(self.label, other.label))