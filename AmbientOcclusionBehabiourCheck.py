import matplotlib.pyplot as plt
import numpy as np

def main():
    t = np.linspace(0, 100, 500)
    density = [0.00001, 0.001, 0.002, 0.005, 0.01, 0.05, 0.1, 0.5, 1]

    attenuation = lambda d, t: 1 - np.exp(-d * t)

    for d in density:
        plt.plot(t, attenuation(d, t), label="density = {}".format(d))
    plt.xlabel("distance")
    plt.ylabel("attenuation")
    plt.legend()
    plt.show()

if __name__ == "__main__":
    main()
