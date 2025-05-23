#include "PluginEditor.h"

PluginEditor::PluginEditor (PluginProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    auto& params = processorRef.apvts;

    auto setupSlider = [this](juce::Slider& s) {
        s.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
        s.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
        addAndMakeVisible(s);
    };

    auto setupLabel = [this](juce::Label& l) {
        l.setJustificationType(juce::Justification::centred);
        addAndMakeVisible(l);
    };

    setupSlider(gainSlider);
    setupSlider(driveSlider);
    setupSlider(toneSlider);

    gainSliderAttach = std::make_unique<SliderAttachment>(params, "gain", gainSlider);
    driveSliderAttach = std::make_unique<SliderAttachment>(params, "drive", driveSlider);
    toneSliderAttach = std::make_unique<SliderAttachment>(params, "tone", toneSlider);

    gainLabel.setText("Gain", juce::dontSendNotification);
    driveLabel.setText("Drive", juce::dontSendNotification);
    toneLabel.setText("Tone", juce::dontSendNotification);

    setupLabel(gainLabel);
    setupLabel(driveLabel);
    setupLabel(toneLabel);

    setSize(600, 400);
    setResizable(true, true);
}

PluginEditor::~PluginEditor()
{
}

void PluginEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void PluginEditor::resized()
{
    // layout the positions of your child components here
    auto area = getLocalBounds().reduced(20);
    auto row = area.removeFromTop(220);

    auto sliderWidth = row.getWidth() / 3;

    gainSlider.setBounds(row.removeFromLeft(sliderWidth));
    driveSlider.setBounds(row.removeFromLeft(sliderWidth));
    toneSlider.setBounds(row.removeFromLeft(sliderWidth));

    auto labelRow = getLocalBounds().reduced(20).removeFromBottom(180 + 0).removeFromBottom(30);
    auto labelWidth = labelRow.getWidth() / 3;

    gainLabel.setBounds(labelRow.removeFromLeft(labelWidth));
    driveLabel.setBounds(labelRow.removeFromLeft(labelWidth));
    toneLabel.setBounds(labelRow.removeFromLeft(labelWidth));

}
