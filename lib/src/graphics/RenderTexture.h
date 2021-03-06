/*
* Viry3D
* Copyright 2014-2018 by Stack - stackos@qq.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#pragma once

#include "Texture.h"
#include "RenderTextureFormat.h"
#include "DepthBuffer.h"
#include "container/List.h"

namespace Viry3D
{
	class RenderTexture: public Texture
	{
	public:
		static void Init();
		static void Deinit();
		static Ref<RenderTexture> Create(
			int width,
			int height,
			RenderTextureFormat format,
			DepthBuffer depth,
			FilterMode filter_mode);
		static Ref<RenderTexture> GetTemporary(int width,
			int height,
			RenderTextureFormat format,
			DepthBuffer depth,
			FilterMode filter_mode);
		static void ReleaseTemporary(Ref<RenderTexture> texture);

		RenderTextureFormat GetFormat() const { return m_format; }
		DepthBuffer GetDepth() const { return m_depth; }

	private:
		RenderTexture();

	private:
		struct Temporary
		{
			Ref<RenderTexture> texture;
			bool in_use;
			float used_time;
		};

		static Map<long long, List<Temporary>> m_temporarys;

		RenderTextureFormat m_format;
		DepthBuffer m_depth;
	};
}
