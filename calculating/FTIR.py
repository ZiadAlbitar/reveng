import numpy as np
from _apodizer import Apodizer as ap

def to_mean(lst):
    return lst - sum(lst)/len(lst)

def symmetrize(lst, points = 512):
    idx = np.argmax(np.abs(lst))
    half = points//2
    start = idx - half
    end = idx + half

    # Handle boundaries safely
    if start < 0:
        start = 0
        end = points
    elif end > len(lst):
        end = len(lst)
        start = end - points

    centered_512 = lst[start:end]
    return centered_512

def rotate(meaned):
    idx = np.argmax(np.abs(meaned))
    rotated = np.roll(meaned, -idx)
    print(idx)
    return rotated

def zero_fill(lst, pad_factor=2):
    return 2**int(np.ceil(np.log2(len(lst) * pad_factor)))

def apodize(ifg, method = 'Hamming', about = 'zpd'):
    apodizer = ap(method)
    return apodizer.apodize(ifg, about = about)

# def apodize(ifg, method = 'Hamming', about = 'zpd'):
#     apodizer = ap(method)
#     return apodizer.apodize(ifg, about = about)

def phase_angle(fft):
    return np.unwrap(np.angle(fft))


def fourier():
    return

