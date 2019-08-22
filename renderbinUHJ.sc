// using the Ctk quark.

(
var cond, score, sndbuf, kernelInfo, sd, decoderUHJ, decoder, filename, scaledRate;
score = CtkScore.new;
s.options.sampleRate_(48000);
s.boot;

// we still need to boot the Server for now to allocate ids for the kernels /* FIX THIS */
s.waitForBoot({
	//		filename = "/home/iain/b-format_demos/Spitfire_Pass_wav-WXYZ.wav";
	filename = thisProcess.argv[0];
filename.postln;
   sndbuf = CtkBuffer.playbuf(filename);
    score.add(sndbuf);
	//	    encoder = FoaEncoderKernel.newUHJ;
    decoder = FoaDecoderKernel.newCIPIC(21);
	decoderUHJ = FoaDecoderKernel.newUHJ;
    s.sync(cond);
    // the FoaEncoderKernel and FoaDecoderKernel classes will return info that can be
    // used to make CtkBuffers for the CtkScore. An array of [path, bufnum, channel] is
    // returned that will line up with the kernel info that the FoaEncode and FoaDecode
    // classes expect
	//	 kernelInfo = encoder.kernelInfo ++ decoder.kernelInfo;
	 kernelInfo = decoder.kernelInfo;
    kernelInfo.do({arg thisInfo;
	     var path, bufnum, channel, buf;
	     #path, bufnum, channel = thisInfo;
        buf = CtkBuffer(path, bufnum: bufnum, channels: channel);
        score.add(buf);
	 });
    sd = CtkSynthDef(\kernelEncodeDecode, {arg buffer;
        var out, src, encode;
scaledRate = BufRateScale.kr(buffer);
        src = PlayBuf.ar(4, buffer, scaledRate);
        //encode = FoaEncode.ar(src, encoder);
		// out = FoaDecode.ar(encode, decoder);
		 out = FoaDecode.ar(src, decoder);
        Out.ar(0, out);
    });
    score.add(sd.note(1.0, sndbuf.duration).buffer_(sndbuf));
    score.write("binaural/".standardizePath ++ "binaural_" ++ filename.basename,
        sampleRate: 48000,
        headerFormat: "WAVE",
        sampleFormat: "float",
        options: ServerOptions.new.numOutputBusChannels_(2)
        );

	 kernelInfo = decoderUHJ.kernelInfo;
    kernelInfo.do({arg thisInfo;
	     var path, bufnum, channel, buf;
	     #path, bufnum, channel = thisInfo;
        buf = CtkBuffer(path, bufnum: bufnum, channels: channel);
        score.add(buf);
	 });
    sd = CtkSynthDef(\kernelDecodeUHJ, {arg buffer;
        var out, src, encode;
        src = PlayBuf.ar(4, buffer, scaledRate);
        //encode = FoaEncode.ar(src, encoder);
		// out = FoaDecode.ar(encode, decoder);
		 out = FoaDecode.ar(src, decoderUHJ);
        Out.ar(0, out);
    });
    score.add(sd.note(1.0, sndbuf.duration).buffer_(sndbuf));
    score.write("stereo/".standardizePath ++ "stereo_" ++ filename.basename,
        sampleRate: 48000,
        headerFormat: "WAVE",
        sampleFormat: "float",
        options: ServerOptions.new.numOutputBusChannels_(2)
        );


	//    encoder.free;
    decoder.free;
	decoderUHJ.free;
thisProcess.argv.postln;

0.exit;
})

)

