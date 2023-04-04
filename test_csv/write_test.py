import pandas as pd

class XY:
    def __init__(self, fn, lower_bound = -100, upper_bound = 100):
        self.x = [x for x in range(lower_bound, upper_bound)]
        self.y = [fn(x) for x in self.x]
    
    def write(self, path):
        df = pd.DataFrame({'x': self.x, 'y': self.y})
        df.to_csv(path)


XY(lambda x: x * x).write('square.csv')
XY(lambda x: x * x * x).write('cube.csv')
print(XY(lambda x: x*x*x).y)