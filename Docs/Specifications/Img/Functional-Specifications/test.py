from scipy.io import wavfile
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import find_peaks

# Replace 'path_to_your_file.wav' with the actual file path of your WAV file
wav_path = 'Sound_Anti_Theft.wav'
sample_rate, samples = wavfile.read(wav_path)

# Check if stereo and convert to mono by averaging channels if necessary
if samples.ndim > 1:
    samples = samples.mean(axis=1)

# Perform a Fourier transform on the audio signal
frequencies = np.fft.rfftfreq(len(samples), 1/sample_rate)
magnitude = np.abs(np.fft.rfft(samples)) / len(samples)

# Find peak frequencies
peaks, properties = find_peaks(magnitude, height=0)
peak_frequencies = frequencies[peaks]

# Find the most dominant peak frequency with the highest peak
dominant_peak_index = np.argmax(properties['peak_heights'])
dominant_frequency = peak_frequencies[dominant_peak_index]

# Get the duration of the audio in seconds
duration = samples.shape[0] / sample_rate

# Create an array of timestamps
timestamps = np.arange(0, len(samples)/sample_rate, 1/sample_rate)

# Ensure that timestamps and samples are the same length
if len(timestamps) > len(samples):
    timestamps = timestamps[:len(samples)]

# Plot the waveform
plt.figure(figsize=(15, 5))
plt.plot(timestamps, samples, color='#0BA37F')
plt.title('Audio Waveform')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.xlim(0, timestamps[-1])
# plt.show()
# save the plot
plt.savefig('Waveform_Anti_Theft.png')


# Plot the audio spectrum
plt.figure(figsize=(15, 5))
plt.plot(frequencies, magnitude, color='#0BA37F')
plt.title('Audio Spectrum')
plt.xlabel('Frequency [Hz]')
plt.ylabel('Magnitude')
plt.xlim(0, sample_rate / 2)  # Display only up to Nyquist frequency
plt.grid(True)
# plt.show()
# save the plot
plt.savefig('Spectrum_Analysis_Anti_Theft.png')

print(f"The most dominant frequency is: {dominant_frequency} Hz")
