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
    
class Triangle3D:
    def __init__(self, dot1, dot2, dot3):
        self.dot1 = dot1
        self.dot2 = dot2
        self.dot3 = dot3

    def calculate_perimeter(self):
        edge1 = self.dot1.distance_to(self.dot2)
        edge2 = self.dot1.distance_to(self.dot3)
        edge3 = self.dot2.distance_to(self.dot3)

        perimeter = (edge1 + edge2 + edge3)
        return perimeter
    
    def calculate_area(self):
        edge1 = self.dot1.distance_to(self.dot2)
        edge2 = self.dot1.distance_to(self.dot3)
        edge3 = self.dot2.distance_to(self.dot3)
        s = (edge1 + edge2 + edge3) / 2
        area = math.sqrt(s * (s - edge1) * (s - edge2) * (s - edge3))
        return area