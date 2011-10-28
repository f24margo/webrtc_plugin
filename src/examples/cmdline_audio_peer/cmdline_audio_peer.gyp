# Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
#
# Use of this source code is governed by a BSD-style license
# that can be found in the LICENSE file in the root of the source
# tree. An additional intellectual property rights grant can be found
# in the file PATENTS.  All contributing project authors may
# be found in the AUTHORS file in the root of the source tree.

{
  'includes': [
    '../../../third_party/webrtc/trunk/src/build/common.gypi',
  ],
  'targets': [
        {
            'target_name': 'cmdline_audio_peer',
            'type': 'executable',
            'sources': [
                'main.cpp',
                'TestPeerConnectionClient.h',
                'TestPeerConnectionClient.cpp',
                'TestPeerConnectionObserver.h',
                'TestPeerConnectionObserver.cpp',
                'TestDefaults.h',
                'TestDefaults.cpp',
                'TestSocketServer.h',
                'TestSocketServer.cpp',
                'TestClientShell.h'
                'ThreadSingle.h',
            ],
            'dependencies': [
                '../../../third_party/webrtc/trunk/third_party_mods/libjingle/libjingle.gyp:libjingle_app',
            ],
            'include_dirs': [
                '../../../third_party/webrtc/trunk/third_party/libjingle/source',
                '../../../third_party/webrtc/trunk/third_party_mods/libjingle/source',
            ],
        },
      ],  # targets
}
