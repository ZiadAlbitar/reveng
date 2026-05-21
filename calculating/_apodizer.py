import numpy as np

class Apodizer:
    def __init__(self, method='hamming', sigma=0.25):
        self.method = method.lower().replace("_", "-")
        self.sigma = sigma
        
        # Map methods to mathematical functions
        self._methods = {
            'none': lambda x: np.ones_like(x),
            'rectangular': lambda x: np.ones_like(x),
            'hamming': lambda x: 0.54 + 0.46 * np.cos(2 * np.pi * x),
            'hann': lambda x: np.cos(np.pi * x)**2,
            'gauss': lambda x: np.exp(-x**2 / (2 * self.sigma**2)),
            'triangular': lambda x: 1 - 2 * np.abs(x),
            'flattop': self._flattop,
            'blackman-harris-3': lambda x: self._bh(x, [0.42323, 0.49755, 0.07922]),
            'blackman-harris-4': lambda x: self._bh(x, [0.35875, 0.48829, 0.14128, 0.01168]),
        }

        if self.method not in self._methods:
            raise KeyError(f"Method '{method}' not supported.")

    def _bh(self, x, coeffs):
        """Generalized Blackman-Harris calculation."""
        return sum(c * np.cos(2 * i * np.pi * x) for i, c in enumerate(coeffs))

    def _flattop(self, x):
        coeffs = [0.21557895, 0.41663158, 0.277263158, 0.083578947, 0.006947368]
        return self._bh(x, coeffs)

    def get_window(self, length):
        """Generates the raw window array centered at 0 [-0.5 to 0.5]."""
        x = np.linspace(-0.5, 0.5, length)
        return self._methods[self.method](x)

    def apodize(self, data, about='center'):
        """
        Applies the window to data.
        'center': Window peaks in the middle of the array.
        'edges': Window peaks at index 0 (assumes rotated/circular data).
        'zpd': Window peaks at the array's absolute maximum.
        """
        n = len(data)
        window = self.get_window(n)

        if about == 'center':
            return data * window
        elif about == 'edges':
            # Roll the window so the peak (center) moves to index 0
            return data * np.roll(window, n // 2)
        elif about == 'zpd':
            print("hej")
            zpd_idx = np.argmax(np.abs(data))
            # Align window peak with ZPD
            return data * np.roll(window, zpd_idx - (n // 2))
        else:
            raise ValueError("Support for 'about' is: center, edges, zpd")

    def plot_window(self):
        import matplotlib.pyplot as plt
        win = self.get_window(1000)
        x = np.linspace(-0.5, 0.5, 1000)
        plt.fill_between(x, win, alpha=0.3)
        plt.plot(x, win)
        plt.title(f"Window: {self.method.capitalize()}")
        plt.show()

if __name__ == '__main__':
    apdz = Apodizer(method='hamming')
    apdz.plot_window()