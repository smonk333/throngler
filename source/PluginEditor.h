#pragma once

#include "PluginProcessor.h"
#include "BinaryData.h"
#include "melatonin_inspector/melatonin_inspector.h"

//==============================================================================
class PluginEditor : public juce::AudioProcessorEditor
{
public:
    explicit PluginEditor (PluginProcessor&);
    ~PluginEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginProcessor& processorRef;

    // set up sliders
    juce::Slider gainSlider, driveSlider, toneSlider;

    // set up labels
    juce::Label gainLabel, driveLabel, toneLabel;

    // set up slider attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainSliderAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveSliderAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> toneSliderAttach;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
