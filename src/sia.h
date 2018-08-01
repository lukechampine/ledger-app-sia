#define U8BE(buf, off) (((uint64_t)(U4BE(buf, off)) << 32) | ((uint64_t)(U4BE(buf, off + 4)) & 0xFFFFFFFF))

// exception codes
#define SW_DEVELOPER_ERR 0x6B00
#define SW_INVALID_PARAM 0x6B01
#define SW_USER_REJECTED 0x6985
#define SW_OK            0x9000

// bin2hex converts binary to hex and appends a final NUL byte.
void bin2hex(uint8_t *out, uint8_t *in, uint64_t inlen);

// bin2b64 converts binary to base64 (standard encoding) and appends a final
// NUL byte. It returns the length of the string.
int bin2b64(uint8_t *out, uint8_t *in, uint64_t inlen);

// bin2dec converts an unsigned integer to a decimal string and appends a
// final NUL byte. It returns the length of the string.
int bin2dec(uint8_t *out, uint64_t n);

// validCur return true if cur is a valid Sia-encoded currency value.
bool validCur(uint8_t *cur);

// cur2dec converts a Sia-encoded currency value to a decimal string and
// appends a final NUL byte. It returns the length of the string.
int cur2dec(uint8_t *out, uint8_t *cur);

// extractPubkeyBytes converts a Ledger-style public key to a Sia-friendly
// 32-byte array.
void extractPubkeyBytes(unsigned char *keyBytes, cx_ecfp_public_key_t *publicKey);

// pubkeyToSiaAddress converts a Ledger pubkey to a Sia wallet address.
void pubkeyToSiaAddress(uint8_t *out, cx_ecfp_public_key_t *publicKey);

// deriveSiaKeypair derives an Ed25519 key pair from an index and the Ledger
// seed. Either privateKey or publicKey may be NULL.
void deriveSiaKeypair(uint32_t index, cx_ecfp_private_key_t *privateKey, cx_ecfp_public_key_t *publicKey);

// deriveAndSign derives an Ed25519 private key from an index and the
// Ledger seed, and uses it to produce a 64-byte signature of the provided
// 32-byte hash. The key is cleared from memory after signing.
void deriveAndSign(uint32_t index, const uint8_t *hash, uint8_t *signature);
