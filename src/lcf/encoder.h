/*
 * This file is part of liblcf. Copyright (c) liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#ifndef LCF_ENCODER_H
#define LCF_ENCODER_H
#include <vector>
#include <string>

#if LCF_SUPPORT_ICU
class UConverter;
#endif

namespace lcf {

class Encoder {
	public:
		explicit Encoder(std::string encoding);

		Encoder(const Encoder&) = delete;
		Encoder& operator=(const Encoder&) = delete;

		~Encoder();

		/**
		 * Converts from the specified encoding to UTF-8
		 *
		 * @param str String to encode to UTF-8
		 */
		void Encode(std::string& str);

		/**
		 * Converts from UTF-8 to the specified encoding
		 *
		 * @param str String to decode from UTF-8
		 */
		void Decode(std::string& str);

		bool IsOk() const;

		const std::string& GetEncoding() const;
	private:
#if LCF_SUPPORT_ICU
		void Init();
		void Reset();
		void Convert(std::string& str, UConverter* conv_dst, UConverter* conv_src);

		UConverter* _conv_storage = nullptr;
		UConverter* _conv_runtime = nullptr;
		std::vector<char> _buffer;
#else
		void Init() {}
		void Reset() {}
		void Convert(std::string&, void*, void*) {}
		void* _conv_storage = nullptr;
		void* _conv_runtime = nullptr;
#endif
		std::string _encoding;
};


inline const std::string& Encoder::GetEncoding() const {
	return _encoding;
}

} //namespace lcf

#endif
