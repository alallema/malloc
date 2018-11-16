
mmap :
adress NULL -> mmap
taille de la zone allouee + 1
type de protection lire ecrire
flag pour type de memoire : memoire anonyme MAP_ANON
							memoire privee MAP_PRIVATE

gcc -shared -o lib.so file.c
setenv
setenv DYLD_LIBRARY_PATH .
setenv DYLD_INSERT_LIBRARIES lib.so
setenv DYLD_FORCE_FLAT_NAMESPACE 1

https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/DynamicLibraries/100-Articles/UsingDynamicLibraries.html

mapping virtual memory page -> 4Kb
stack -> 64Kb
getconf PAGE_SIZE -> 4096 bytes

cluster of pages

16 bytes resolution

Tiny -> 512 -- 15 * get
Small -> 4096 -- 101 * get

Tiny -> 128 -- 8 * get
Small -> 2048 -- 64 * get

Tiny Apple -> 16 bytes -> 215 bytes
Small Apple -> 512 bytes -> 4096 bytes
Large 4kB

typedef struct		s_zone
{
	int				type;
	size_t			remaining;
	t_block			*base;
	struct s_zone	*next;
}					t_zone;

# define BLOCK_SIZE sizeof(t_block)
# define ZONE_SIZE sizeof(t_zone)

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8
#define align4(x) (((((x) -1) >> 2) << 2) +4)

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(p) (((size_t)(p) + (ALIGNMENT-1)) & ~0x7)

/* Basic constants and macros */
#define WSIZE       4	/* word size (bytes) */  
#define DSIZE       8	/* doubleword size (bytes) */
#define CHUNKSIZE   16	/* initial heap size (bytes) */
#define MINIMUM    24  /* minimum block size */

#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc)  ((size) | (alloc))

/* Read and write a word at address p */
#define GET(p)       (*(int *)(p))
#define PUT(p, val)  (*(int *)(p) = (val))

/* Read the size and allocated fields from address p */
#define GET_SIZE(p)  (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp)       ((void *)(bp) - WSIZE)
#define FTRP(bp)       ((void *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp)  ((void *)(bp) + GET_SIZE(HDRP(bp)))
#define PREV_BLKP(bp)  ((void *)(bp) - GET_SIZE(HDRP(bp) - WSIZE))

/* Given block ptr bp, compute address of next and previous free blocks */
#define NEXT_FREEP(bp)(*(void **)(bp + DSIZE))
#define PREV_FREEP(bp)(*(void **)(bp))

void *
malloc_zone_malloc(malloc_zone_t *zone, size_t size) {
		void	*ptr;
		if (malloc_check_start && (malloc_check_counter++ >= malloc_check_start)) {
				internal_check();
		}
		if (size > MALLOC_ABSOLUTE_MAX_SIZE) {
				return NULL;
		}
		ptr = zone->malloc(zone, size);
		if (malloc_logger) malloc_logger(MALLOC_LOG_TYPE_ALLOCATE | MALLOC_LOG_TYPE_HAS_ZONE, (uintptr_t)zone, (uintptr_t)size, 0, (uintptr_t)ptr, 0);
		return ptr;
}

/*
 * Layout of a tiny region
  */
typedef uint32_t tiny_block_t[4]; // assert(TINY_QUANTUM == sizeof(tiny_block_t))

typedef struct tiny_header_inuse_pair
{
		uint32_t	header;
		uint32_t	inuse;
} tiny_header_inuse_pair_t;

typedef struct region_trailer
{
		struct region_trailer	*prev;
		struct region_trailer	*next;
		boolean_t			recirc_suitable;
		unsigned			bytes_used;
		mag_index_t			mag_index;
} region_trailer_t;

typedef struct tiny_region
{
		tiny_block_t blocks[NUM_TINY_BLOCKS];

		region_trailer_t trailer;

		// The interleaved bit arrays comprising the header and inuse bitfields.
		// The unused bits of each component in the last pair will be initialized to sentinel values.
		tiny_header_inuse_pair_t pairs[CEIL_NUM_TINY_BLOCKS_WORDS];

		uint8_t pad[TINY_REGION_SIZE - (NUM_TINY_BLOCKS * sizeof(tiny_block_t)) - TINY_METADATA_SIZE];
} *tiny_region_t;

/*
 * Layout of a small region
  */
	typedef uint32_t small_block_t[SMALL_QUANTUM/sizeof(uint32_t)];

	typedef struct small_region
	{
			    small_block_t blocks[NUM_SMALL_BLOCKS];

					    region_trailer_t trailer;
							    
									    msize_t small_meta_words[NUM_SMALL_BLOCKS];
											    
													    uint8_t pad[SMALL_REGION_SIZE - (NUM_SMALL_BLOCKS * sizeof(small_block_t)) - SMALL_METADATA_SIZE];
	} *small_region_t;
