const {AudioFormatManager, WavAudioFormat} = require("../lib/binding.js");

test("AudioFormatManager", () => {
    const afm = new AudioFormatManager();
    afm.registerBasicFormats();
    const knownFormats = afm.getNumKnownFormats();
    expect(knownFormats).toBeGreaterThan(0);
})

test("AudioFormatManager -> registerFormat", () => {
    const afm = new AudioFormatManager();
    const wavAudioFormat = new WavAudioFormat();
    afm.registerFormat(wavAudioFormat, true);
    const knownFormats = afm.getNumKnownFormats();
    expect(knownFormats).toBe(1);
})

test("AudioFormatManager -> knownFormats", () => {
    const afm = new AudioFormatManager();
    const wavAudioFormat = new WavAudioFormat();
    afm.registerFormat(wavAudioFormat, true);
    const formats = afm.knownFormats;
    console.log(formats);

    const numKnownFormats = afm.getNumKnownFormats();
    expect(formats).toHaveLength(numKnownFormats);
    
})