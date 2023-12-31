#ifndef PIECE_LOGIC_H
#define PIECE_LOGIC_H

//-----------------------------------------------------------------------------------------

#include "ch_piece.h"
using namespace piece;

//-----------------------------------------------------------------------------------------

class pawn_t : public piece_t {
    private:
    public:
    //constructor & destructor
    explicit pawn_t (short color_, coordinates_t coord_);
    virtual ~pawn_t ();
    //others methods
    virtual bool can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
    virtual bool is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
};

class knight_t : public piece_t {
    private:

    public:
    //constructor & destructor
    explicit knight_t (short color_, coordinates_t coord_);
    virtual ~knight_t ();
    //others methods
    virtual bool can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
    virtual bool is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
};

class bishop_t : public piece_t {
    private:
    public:
    //constructor & destructor
    explicit bishop_t (short color_, coordinates_t coord_);
    virtual ~bishop_t ();
    //others methods
    virtual bool can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
    virtual bool is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
};

class rook_t : public piece_t {
    private:

    public:
    //constructor & destructor
    explicit rook_t (short color_, coordinates_t coord_);
    virtual ~rook_t ();
    //others methods
    virtual bool can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
    virtual bool is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
};

class queen_t : public piece_t {
    private:
    public:
    //constructor & destructor
    explicit queen_t (short color_, coordinates_t coord_);
    virtual ~queen_t ();
    //others methods
    virtual bool can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
    virtual bool is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
};

class king_t : public piece_t {
    private:
        bool is_checked;
    public:
    //constructor & destructor
    explicit king_t (short color_, coordinates_t coord_);
    virtual ~king_t ();
    //others methods
    virtual bool can_move (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
    virtual bool is_jump  (piece_t* (&cells)[SIZE_OF_BOARD][SIZE_OF_BOARD],
                           const coordinates_t from, const coordinates_t to) const;
    inline  int  set_check() {is_checked = true; return 0;};
};

//-----------------------------------------------------------------------------------------

#endif
