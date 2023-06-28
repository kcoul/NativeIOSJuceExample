#pragma once

#include <functional>
#include <JuceHeader.h>

class AudioEngine
{
public:
    //==============================================================================
    AudioEngine();
    ~AudioEngine();

    //==============================================================================
    void play(const char* url);
    void stop();

    //==============================================================================
    void pause();
    void resume();

    //==============================================================================
    void setRoomSize(float roomSize);    // roomSize goes from 0 to 1
    void setLowpassCutoff(float cutoff); // cutoff goes from 0 to 1 (1 being nyquist frequency)
    // TODO add more DSP methods

    //==============================================================================
    // You can only have the waveform component be in single parent view

    // returns a point to the native handle of the component: only needed on windows
    void* addWaveformComponentToNativeParentView (void* nativeView);
    void removeWaveformComponentFromNativeParentView();
    void setWaveformComponentSize (int width, int height);  // Needed for iOS

    void setPlaybackFinishedCallback (std::function<void()>); // 2

    //==============================================================================
    AudioEngine(const AudioEngine&) = delete;
    AudioEngine(AudioEngine&&) = delete;
    AudioEngine& operator=(const AudioEngine&) = delete;
    AudioEngine& operator=(AudioEngine&&) = delete;
private:
    struct Pimpl;
    Pimpl* pimpl;
};
