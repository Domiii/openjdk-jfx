/*
 * Copyright (C) 2017 Igalia S.L. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "config.h"
#include "VREyeParameters.h"

#include "VRFieldOfView.h"

namespace WebCore {

VREyeParameters::VREyeParameters(const FloatPoint3D& offset, const VRPlatformDisplayInfo::FieldOfView& fieldOfView, const RenderSize& renderSize)
    : m_fieldOfView(VRFieldOfView::create(fieldOfView))
    , m_offset(offset)
    , m_renderSize(renderSize)
{
}

Ref<Float32Array> VREyeParameters::offset() const
{
    auto offset = Float32Array::create(3);
    RELEASE_ASSERT(offset);
    float* offsetData = offset->data();
    offsetData[0] = m_offset.x();
    offsetData[1] = m_offset.y();
    offsetData[2] = m_offset.z();
    return offset.releaseNonNull();
}

const VRFieldOfView& VREyeParameters::fieldOfView() const
{
    return m_fieldOfView;
}

unsigned VREyeParameters::renderWidth() const
{
    return m_renderSize.width;
}

unsigned VREyeParameters::renderHeight() const
{
    return m_renderSize.height;
}

} // namespace WebCore
