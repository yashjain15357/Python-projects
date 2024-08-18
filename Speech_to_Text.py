import sounddevice as sd
from scipy.io.wavfile import write
import assemblyai as aai

print("Now Start to Speek 20s")
# Set the sampling frequency, which determines the quality of the audio recording.
# A higher sampling frequency captures more detail but results in larger files.
freq = 16000  # 16 kHz is commonly used for speech recognition, providing a balance between quality and file size.

# Define the duration of the recording in seconds.
duration = 20  # The recording will last for 10 seconds.

# Start the recorder with the specified duration and sampling frequency.
# The 'channels=1' parameter indicates that the recording will be in mono (single channel).
# 'sd.rec()' starts the recording and stores the audio data as a NumPy array.
recording = sd.rec(int(duration * freq), samplerate=freq, channels=1)

# Wait until the recording is finished.
# 'sd.wait()' blocks the execution until the recording is complete.
sd.wait()

print("\nNow your Speech going for process.......")

# Save the recorded audio to a file named "recording0.wav" in the current directory.
# The 'write()' function takes the filename, sampling frequency, and the audio data (NumPy array) as input.
write("recording0.wav", freq, recording)

# Initialize AssemblyAI by setting the API key.
# AssemblyAI is a service that provides speech-to-text capabilities through an API.
aai.settings.api_key = "6b8c2977ace24ce284977e0407e6d612"  # Replace this with your actual API key.

# Create a transcriber object from AssemblyAI.
# The transcriber will be used to send the audio file to AssemblyAI for transcription.
transcriber = aai.Transcriber()

# Use the transcriber to transcribe the recorded audio file ("recording0.wav").
# The 'transcribe()' method sends the audio file to AssemblyAI and retrieves the transcript.
transcript = transcriber.transcribe("recording0.wav")

# Print the text of the transcription to the console.
# 'transcript.text' contains the transcription of the audio file as a string.
print("\nYour speech to text output : \n")
print(transcript.text)

