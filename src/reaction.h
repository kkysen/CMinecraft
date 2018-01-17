//
// Created by kkyse on 12/29/2017.
//

#ifndef CASTROPARTY_REACTION_H
#define CASTROPARTY_REACTION_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t Reaction;

// Non compressed version of Reaction
//typedef struct {
//    const bool is_accelerating;
//    const bool is_turning;
//    const bool is_shooting;
//    const bool is_terminated;
//    const bool sent_hash;
//} Reaction;

// @formatter:off

#define REACTION_NONE            ((Reaction) 0u)
#define REACTION_IS_ACCELERATING ((Reaction) (1u << 0))
#define REACTION_IS_TURNING      ((Reaction) (1u << 1))
#define REACTION_IS_SHOOTING     ((Reaction) (1u << 2))
#define REACTION_IS_TERMINATED   ((Reaction) (1u << 3))
#define REACTION_SENT_HASH       ((Reaction) (1u << 4))

#define Reaction_is_accelerating(reaction) ((bool) ((reaction) & REACTION_IS_ACCELERATING))
#define Reaction_is_turning(     reaction) ((bool) ((reaction) & REACTION_IS_TURNING     ))
#define Reaction_is_shooting(    reaction) ((bool) ((reaction) & REACTION_IS_SHOOTING    ))
#define Reaction_is_terminated(  reaction) ((bool) ((reaction) & REACTION_IS_TERMINATED  ))
#define Reaction_sent_hash(      reaction) ((bool) ((reaction) & REACTION_SENT_HASH      ))

#define Reaction_set_is_accelerating(reaction, is_accelerating) \
    ((reaction) | (is_accelerating) ? REACTION_IS_ACCELERATING : REACTION_NONE)

#define Reaction_set_is_turning(     reaction, is_turning     ) \
    ((reaction) | (is_turning)      ? REACTION_IS_TURNING      : REACTION_NONE)

#define Reaction_set_is_shooting(    reaction, is_shooting    ) \
    ((reaction) | (is_shooting)     ? REACTION_IS_SHOOTING     : REACTION_NONE)

#define Reaction_set_is_terminated(  reaction, is_terminated  ) \
    ((reaction) | (is_terminated)   ? REACTION_IS_TERMINATED   : REACTION_NONE)

#define Reaction_set_sent_hash(      reaction, sent_hash      ) \
    ((reaction) | (sent_hash)       ? REACTION_SENT_HASH       : REACTION_NONE)

#define Reaction_new(is_accelerating, is_turning, is_shooting, is_terminated, sent_hash) \
    (REACTION_NONE \
    |  ((is_accelerating) ? REACTION_IS_ACCELERATING : REACTION_NONE) \
    |  ((is_turning)      ? REACTION_IS_TURNING      : REACTION_NONE) \
    |  ((is_shooting)     ? REACTION_IS_SHOOTING     : REACTION_NONE) \
    |  ((is_terminated)   ? REACTION_IS_TERMINATED   : REACTION_NONE) \
    |  ((sent_hash)       ? REACTION_SENT_HASH       : REACTION_NONE) \
    | REACTION_NONE)

// @formatter:on

// don't delete, but ignore
#define ignore() \
    Reaction reaction = Reaction_new(false, false, false, false, false); \
    \
    reaction = Reaction_set_is_accelerating(reaction, true); \
    reaction = Reaction_set_is_turning     (reaction, true); \
    reaction = Reaction_set_is_shooting    (reaction, true); \
    reaction = Reaction_set_is_terminated  (reaction, true); \
    reaction = Reaction_set_sent_hash      (reaction, true); \
    \
    bool b = false; \
    b = Reaction_is_accelerating(reaction); \
    b = Reaction_is_turning     (reaction); \
    b = Reaction_is_shooting    (reaction); \
    b = Reaction_is_terminated  (reaction); \
    b = Reaction_sent_hash      (reaction); \
    return reaction;

#undef ignore

Reaction Reaction_poll();

#endif // CASTROPARTY_REACTION_H
