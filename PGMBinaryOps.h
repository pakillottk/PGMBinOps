
#ifndef PGMBINARYOPS_H
#define	PGMBINARYOPS_H

#include <stdint.h>
/*
 *      Lightweight module for typical bin/hex operations.
 * 
 *      Written by: Fco. Gázquez (pmgmsc@gmail.com)
 *      Github: github.com/pakillottk
 *      
 */
namespace pgmbin {
    /*
     *  Given - Byte ba and Byte cd
     *  Return - 2 bytes of the form: 0xbacd                  
     */
    inline uint16_t combine(uint8_t ba, uint8_t cd) {
        return (ba << 8) | cd;
    }    
    /*
     *  Given - Byte lb (low byte) and Byte hb (high byte)
     *  Return - result of combine( hb. lb )                         
     */
    inline uint16_t combineLittleEndian(uint8_t lb, uint8_t hb) {
        return combine(hb,lb);
    }    
    /*
     *  Given -  Byte hb (high byte) and Byte lb (low byte) 
     *  Return - result of combine( hb. lb )                            
     */
    inline uint16_t combineBigEndian( uint8_t hb, uint8_t lb ) {
        return combine(hb,lb);
    }    
    /*
     *  Given -  n (1-based) and Byte byte 
     *  Return - value of nibble n in byte                                 
     */
    template <short n>
    inline uint8_t getNibble( uint8_t byte ) {
        return (byte >> (n-1)) & 0xF;
    }    
    /*
     *  Given -  bit (1-based), set (0 or 1) and Byte byte 
     *  Return - Changes bit of byte to set and returns new byte                               
     */
    template <short bit>
    inline char setBitAt( char set, uint8_t byte ) {
        return set ? byte |= (bit) : byte &= ~(bit);
    } 
    /*
     *  Given -  bit (bit 1-based) and Byte byte 
     *  Return - value of bit n in byte                                
     */
    template <short bit>
    inline char getBitAt(uint8_t byte ) {
        return (byte >> (bit-1)) & 0x1;
    }
};

#endif	/* PGMBINARYOPS_H */

