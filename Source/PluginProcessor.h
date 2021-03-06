#pragma once

#include <JuceHeader.h>

#define MAX_DELAY_TIME 2

class Delay03AudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    Delay03AudioProcessor();
    ~Delay03AudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    float linear_interpolation(float sample_x, float sample_x1, float inPhase);

private:
    
    float mLFOPhase;
    
    float mDelayTimeSmoothed;
    
    AudioParameterFloat* mDryWetParameter;
    AudioParameterFloat* mDepthParameter;
    AudioParameterFloat* mFeedbackParameter;
    AudioParameterFloat* mRateParameter;
    
    float mFeedbackLeft;
    float mFeedbackRight;
    
    float mDelayTimeInSamples;
    float mDelayReadHead;
    
    int mCircularBufferLength;
    int mCircularBufferWriteHead;
    
    float* mCircularBufferLeft;
    float* mCircularBufferRight;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Delay03AudioProcessor)
};

