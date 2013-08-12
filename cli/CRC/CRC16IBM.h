#ifndef CRC16IBM_H
#define CRC16IBM_H

#include "CRC.h"

class CRC16IBM : public CRC
{
	private:
		uint16_t lookupTable [256];
		uint16_t invLookupTable [256];
	protected:
		virtual CRCType getPolynomial() const;
		virtual CRCType getPolynomialReverse() const;
		virtual size_t getNumBytes() const;
		virtual size_t getNumBits() const;

		virtual CRCType makeNextChecksum(
			const CRCType &prevChecksum,
			unsigned char c) const;

		virtual CRCType makePrevChecksum(
			const CRCType &nextChecksum,
			unsigned char c) const;

		virtual CRCType computePatch(
			const CRCType &desiredChecksum,
			const File::OffsetType &desiredPosition,
			File &inputFile,
			const bool &overwrite) const;
	public:
		CRC16IBM();
};

#endif
