/* Include ------------------------------------------------------------------ */
#include "config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "gpio_hal.h"
#include "timer_hal.h"
#include "uart_hal.h"
#include <stdint.h>

#include "ei_run_classifier.h"
#include "ei_classifier_porting.h"

extern "C" {
#include "eta_bsp.h"
}

#define TASK_STACK_SIZE  2048

/** UART used for edge impulse communication */
tUart etaUart;

static const float features[] = {
    // copy raw features here (for example from the 'Live classification' page)
    // see https://docs.edgeimpulse.com/docs/running-your-impulse-ecm353

0x787260, 0x545a4c, 0xb2b3b6, 0x9ea39b, 0x5b6247, 0x4f5a3a, 0x727365, 0xbab9b6, 0x999b92, 0x76786d, 0x797a72, 0x717467, 0x66695c, 0x66675e, 0x686b62, 0x6d7067, 0x787b74, 0x8c8e89, 0x9c9d98, 0xa6a7a4, 0xaeadac, 0xb4afb4, 0xb7b2b2, 0xbbb5b6, 0xc0b5bb, 0xc4b8ba, 0xc4babb, 0xc3b9ba, 0xc0b6b7, 0xbcb4b5, 0xb5b4b2, 0xb4b4b6, 0xc2998c, 0x8e7b73, 0x6c736f, 0x807c6c, 0x5b6242, 0x525a3a, 0x7d7d70, 0xc2c1bd, 0x8d8f85, 0x76776c, 0x777870, 0x6f7265, 0x636759, 0x63695a, 0x666a5f, 0x6a6c64, 0x737a72, 0x898f87, 0x9a9d97, 0xa5a6a3, 0xacaba9, 0xb3afae, 0xb7b2b0, 0xbbb5b7, 0xc1b5bb, 0xc5b9ba, 0xc4babb, 0xc4babb, 0xc3b9b9, 0xbdb7b3, 0xb9b6b1, 0xb8b5b3, 0xb5948b, 0xc8b1b1, 0xccccd1, 0x7b7763, 0x585f3d, 0x595d40, 0x898a7e, 0xc4c6c0, 0x818578, 0x767a6c, 0x74776b, 0x6c7264, 0x5f6656, 0x616955, 0x636a5a, 0x666d62, 0x727a71, 0x878f87, 0x979e99, 0xa4a6a4, 0xadacaa, 0xb3b0af, 0xb8b4b3, 0xbbb7b6, 0xc3b8ba, 0xc6b9bb, 0xc7bbbb, 0xc7bbbb, 0xc5bab9, 0xc3bab8, 0xbfb8b6, 0xbdb7b7, 0xc39b93, 0xdec9cc, 0xc9cecf, 0x75725e, 0x575e3d, 0x5c6147, 0x8d8e85, 0xbabbb5, 0x7d8172, 0x767c6d, 0x717869, 0x697162, 0x5d6657, 0x5d6858, 0x616a59, 0x656d60, 0x707b72, 0x869187, 0x95a09a, 0xa3a7a5, 0xabadaa, 0xb0b1b1, 0xb5b3b3, 0xbcb7b6, 0xc2babb, 0xc6bbbd, 0xcbbfc2, 0xcabebf, 0xc8bcbc, 0xc6bcbb, 0xc3bbbb, 0xc1bbbb, 0xc69e93, 0xe7d9df, 0xb8bdb9, 0x6a6a53, 0x595f3f, 0x656651, 0x9b9d95, 0xb3b8b0, 0x7a7e70, 0x747c6d, 0x6e7969, 0x677161, 0x5b6656, 0x586757, 0x5c6a59, 0x636e61, 0x6f7d71, 0x859289, 0x95a19b, 0xa0a9a4, 0xb1b5b4, 0xbcbfbf, 0xc3c2c0, 0xc3c1bf, 0xc1bdbc, 0xc7c0c1, 0xcbc2c4, 0xcbc1c2, 0xccc1c1, 0xcbbfc0, 0xc6bebe, 0xc4bec0, 0xc6a4a0, 0xe1d8e1, 0xadb1ab, 0x646550, 0x5a6142, 0x6e6c59, 0xacaea7, 0xb0b8af, 0x727b6c, 0x727e6d, 0x6e7969, 0x637060, 0x586655, 0x586957, 0x5a6b59, 0x607161, 0x6d8172, 0x84958c, 0x94a19b, 0xa8b4b0, 0x929a98, 0x5c6660, 0x5b655c, 0x9ba099, 0xc8c7c1, 0xc6c3c2, 0xcbc6c5, 0xcdc4c5, 0xcdc2c3, 0xcdc1c3, 0xccc1c2, 0xcbc0c6, 0xd3b1aa, 0xe7e4ec, 0x9c9e94, 0x646750, 0x5c6145, 0x737362, 0xb7b9b3, 0xacb3a9, 0x6e7a69, 0x717e6d, 0x6b7867, 0x61705e, 0x556755, 0x596a57, 0x5a6d5a, 0x5f7362, 0x6e8372, 0x81968a, 0x9aada5, 0x687871, 0xb140c, 0x600, 0x10a00, 0x162114, 0x8a8f85, 0xcfcdc8, 0xccc3c4, 0xcec5c5, 0xcec3c4, 0xccc2c3, 0xcdc2c4, 0xcdc1c6, 0xcea9a4, 0xe9eaf0, 0x8d8c7e, 0x64674d, 0x5e6248, 0x7b7d6e, 0xbfc3bd, 0xa4aea2, 0x6d7a69, 0x717f6e, 0x687967, 0x616e5d, 0x566855, 0x596c58, 0x586d5c, 0x5d7464, 0x6a8471, 0x859e90, 0x708479, 0x60e08, 0x900, 0x51006, 0x71006, 0x40b00, 0x1b2418, 0xa7aca3, 0xd3ccca, 0xccc4c2, 0xcec4c3, 0xcdc3c3, 0xccc1c4, 0xcec3c7, 0xe1c4c6, 0xe5e7ec, 0x888375, 0x63674f, 0x62654c, 0x838577, 0xc4cbc4, 0x9aa99b, 0x6b7c6b, 0x6e7f6e, 0x677966, 0x5e6f5d, 0x556854, 0x5a6c58, 0x586f5c, 0x5a7463, 0x688471, 0x7e9c8b, 0x243528, 0x800, 0x40f05, 0xa00, 0x20b01, 0x60c03, 0x600, 0x485449, 0xcfcdc9, 0xcdc5c3, 0xcdc3c2, 0xccc2c3, 0xccc1c4, 0xcec3c7, 0xd8bcc0, 0xd9dddf, 0x847f70, 0x616650, 0x656851, 0x8a8c7f, 0xc8d0ca, 0x92a193, 0x6b7c6e, 0x6b7f6f, 0x667966, 0x5a6f5c, 0x546a54, 0x5b705a, 0x59705b, 0x5a745f, 0x6d8a78, 0x637d6d, 0x20e04, 0x51408, 0x1d3227, 0x8150c, 0x700, 0x20901, 0x30901, 0xd170c, 0xa5a7a1, 0xd6ccca, 0xcbc1c1, 0xccc2c3, 0xccc1c4, 0xcec2c6, 0xefd7dc, 0xcfd4d5, 0x807b6c, 0x626650, 0x696c55, 0x909487, 0xcad3cd, 0x8b9b8d, 0x6c7d6e, 0x6a7e6d, 0x657965, 0x5a6e5b, 0x556c56, 0x5a725b, 0x59715c, 0x5a735f, 0x6f8e7a, 0x445b4d, 0x600, 0x20e05, 0x344f43, 0x2e443b, 0x400, 0x20901, 0x30a02, 0x500, 0x70756e, 0xd9d0ce, 0xcbc0c1, 0xccc2c3, 0xcdc1c4, 0xcec1c6, 0xf0dde3, 0xc6cacb, 0x7b7766, 0x646651, 0x6e705a, 0x959a90, 0xccd7d0, 0x849586, 0x6b7f6c, 0x687f6c, 0x627b66, 0x5a6f5b, 0x566d58, 0x59725b, 0x59725f, 0x587463, 0x6b8e78, 0x354e3f, 0x400, 0xb02, 0x2b4237, 0x526b62, 0x8140c, 0x700, 0x30a03, 0x100, 0x4a5448, 0xd0cbc8, 0xcdc1c4, 0xccc0c4, 0xcdbfc4, 0xcfc0c5, 0xf4eaf2, 0xc0c3c0, 0x777561, 0x666852, 0x72755f, 0x9da298, 0xcdd8d2, 0x7f9081, 0x6c806d, 0x69806b, 0x617a65, 0x58705b, 0x557059, 0x58745d, 0x59735f, 0x597563, 0x698d76, 0x364f40, 0x700, 0x10c01, 0xc1b0f, 0x425d4f, 0x253c2f, 0x900, 0x20902, 0x200, 0x353f34, 0xcac5c2, 0xcbbfc3, 0xc8bdc1, 0xcbbdc2, 0xcebec4, 0xefe4f0, 0xbdbfb7, 0x74735e, 0x6a6b55, 0x757862, 0xa0aaa0, 0xcdd9d2, 0x7b8b7c, 0x6d806d, 0x69806b, 0x627a64, 0x58715b, 0x57715b, 0x58745d, 0x59735e, 0x57755f, 0x678c77, 0x466352, 0xc00, 0x20d02, 0x900, 0xa190f, 0x172c20, 0xa160c, 0xd190d, 0x400, 0x2e382d, 0xc4c4c1, 0xc7bdc0, 0xc4b8bc, 0xc5b8bc, 0xc9b9c2, 0xefecf6, 0xb4b6ad, 0x74735e, 0x6c6d58, 0x787b66, 0xa6b1a7, 0xcad7d0, 0x78897a, 0x6e816f, 0x6a816c, 0x647c66, 0x59715b, 0x59735d, 0x59765f, 0x59735d, 0x587660, 0x638772, 0x668876, 0x122213, 0x900, 0x10b03, 0x700, 0x30d04, 0x30e04, 0x91006, 0x70800, 0x3d453d, 0xc6c7c6, 0xc3babd, 0xc0b4b9, 0xc1b4b8, 0xc5b6bf, 0xeaeaf2, 0xafaea6, 0x767360, 0x6e6f59, 0x7c7e6a, 0xafb7b0, 0xc8d5ce, 0x758978, 0x6e8370, 0x68836e, 0x617d67, 0x58735c, 0x59755e, 0x5b7761, 0x5a7560, 0x587961, 0x60866f, 0x759b88, 0x50715e, 0x31105, 0x900, 0x30a02, 0x30a01, 0x500, 0x241e14, 0x472b12, 0x5f5b4c, 0xc7c6c8, 0xc3b8bc, 0xbfb3b7, 0xbcb0b2, 0xbfb2b9, 0xececf3, 0xa8a79e, 0x777361, 0x70725b, 0x7e806c, 0xb3bbb5, 0xc5d3cb, 0x748878, 0x6f8471, 0x69846e, 0x617e67, 0x58755e, 0x5c7862, 0x597a62, 0x587861, 0x597c63, 0x638a72, 0x709684, 0x82a999, 0x506f60, 0x6160b, 0x600, 0x10601, 0x400, 0xa0700, 0x4d2d17, 0x2f2415, 0xa9a7a7, 0xcabfc3, 0xbeb2b5, 0xb9adb0, 0xb9acb1, 0xe6e6ed, 0xa2a198, 0x767461, 0x71715c, 0x808270, 0xb7bfba, 0xc4d0cc, 0x758779, 0x708572, 0x6a856f, 0x637f69, 0x5b7560, 0x5e7c65, 0x5c7e65, 0x5a7c64, 0x5c8068, 0x678e76, 0x769a89, 0x83a497, 0x91b4a6, 0x718f80, 0x384f42, 0x1b2b1e, 0xc170c, 0x3b4a3d, 0x474037, 0x121410, 0xb2b0b1, 0xc8bec1, 0xbdb2b6, 0xb5a9ad, 0xb5a8ad, 0xdedfe3, 0x9e9c91, 0x757462, 0x72715e, 0x828573, 0xbac2bd, 0xc2cdca, 0x76887a, 0x718773, 0x6c8671, 0x65806a, 0x5d7661, 0x607f68, 0x608269, 0x5e8168, 0x62866e, 0x6c927a, 0x7b9f8e, 0x88a99b, 0x8fb0a4, 0x9ebdae, 0xa7c4b5, 0x7c8c7f, 0x7a8677, 0xc4d3cb, 0xb4bab5, 0xa0a3a2, 0xadacaf, 0xc7bcbf, 0xbbafb4, 0xb0a5a9, 0xb0a4a8, 0xd3d5d9, 0x9b988d, 0x767462, 0x73735d, 0x868877, 0xbfc4c0, 0xc2ccc8, 0x768778, 0x738777, 0x6d8672, 0x66836d, 0x5f7963, 0x64826b, 0x63856c, 0x62846e, 0x678a75, 0x739681, 0x81a595, 0x8fb0a3, 0x99b7ab, 0xa0bcae, 0xadc7bb, 0x898f85, 0x9ca296, 0xc8d3d2, 0xc5cbc7, 0xc7c9c8, 0xa9a8ab, 0xc9c0c2, 0xbab0b4, 0xb2a6ab, 0xb1a4aa, 0xcfd2d4, 0x9a968b, 0x767562, 0x74755f, 0x898a7a, 0xc1c6c2, 0xc1cbc7, 0x768777, 0x74887a, 0x708773, 0x6a846f, 0x627b66, 0x66846d, 0x698770, 0x678873, 0x6b8f7b, 0x799c8b, 0x8aac9f, 0x99b8ab, 0xa5c0b5, 0xaac6b9, 0xb7d1c6, 0x717f79, 0x6b756d, 0xc9d5d4, 0xc9cfcd, 0xc5c6c9, 0xafafb1, 0xd1c8cb, 0xc3bac1, 0xbdb0b8, 0xb9acb3, 0x979996, 0x969286, 0x767662, 0x74745f, 0x8c8c7c, 0xc5cac6, 0xc1cbc8, 0x778678, 0x74887b, 0x718775, 0x6c8472, 0x647c6a, 0x6a8672, 0x6b8871, 0x698a75, 0x6e907e, 0x7e9d90, 0x92b0a5, 0xa1bdb1, 0xaac7bb, 0xafcbbf, 0xc0d9ce, 0x546564, 0x566360, 0xc6d0ce, 0xd3d8d7, 0xcbccd0, 0xb6b5b8, 0xd7cfd1, 0xcdc3ca, 0xc8bbc3, 0xc3b6be, 0xc4c5c5, 0x8c8a7a, 0x747461, 0x73735e, 0x8b897b, 0xc6cac6, 0xc2cbc9, 0x778679, 0x77877c, 0x728677, 0x6e8374, 0x667b6d, 0x6d8776, 0x6d8977, 0x6d8a79, 0x739080, 0x839e91, 0x96b1a7, 0xa3c0b3, 0xadc9bd, 0xb7cec5, 0xb9cdc7, 0x6a7a78, 0x768383, 0xb8c2c0, 0xdadddd, 0xc6c9ce, 0xbdbbbf, 0xdbd4d4, 0xd3c8cc, 0xccc2c8, 0xcac0c8, 0xd5d9dc, 0x8c8a7d, 0x6b6c58, 0x6a6c56, 0x817e71, 0xbbbdba, 0xbcc5c1, 0x778478, 0x7a867c, 0x758678, 0x6f8272, 0x667b6e, 0x718779, 0x73897c, 0x718b7b, 0x759182, 0x849f93, 0x96b1a8, 0xa6c1b7, 0xb0cac0, 0xbed1c9, 0xb3c1c1, 0x667473, 0x849191, 0xabb4b4, 0xdcdfde, 0xc1c3c8, 0xc4c2c7, 0xdfd6d7, 0xd7ccd1, 0xd0c6cc, 0xcec4cd, 0xd1d6dc, 0x8b8a80, 0x646850, 0x5f644a, 0x79766b, 0xb4b4b3, 0xb7beb8, 0x778075, 0x778279, 0x738376, 0x6d8073, 0x667a6e, 0x75877c, 0x73897c, 0x728a7a, 0x769081, 0x859e94, 0x98afa9, 0xa9bfb8, 0xb2c8c2, 0xc2d4cc, 0xa0acac, 0x667373, 0xa5adad, 0x959ea1, 0xdfe1e2, 0xbfc0c5, 0xc9c7cc, 0xe0d6d8, 0xdacdd5, 0xd4c8cf, 0xd3c7d1, 0xc8cfd8, 0x8b8e85, 0x5d644c, 0x575d42, 0x727164, 0xb1b1b0, 0xb7bcb7, 0x767c72, 0x758076, 0x717f73, 0x6f7c71, 0x69786e, 0x76877c, 0x72877b, 0x71877a, 0x788d81, 0x869b94, 0x9aaeaa, 0xacbeb9, 0xb3c6c1, 0xc7d6d0, 0x859293, 0x727e7c, 0xbbc1c2, 0x838a8f, 0xe3e2e6, 0xbebfc4, 0xcdcbd1, 0xe0d6d8, 0xd9cdd3, 0xd4c9d0, 0xd2c9d3, 0xa9b1ba, 0x8f9289, 0x5c624b, 0x52593c, 0x6d6d5f, 0xb0b0af, 0xbabbb8, 0x757a70, 0x747c73, 0x727d73, 0x727b72, 0x6b776e, 0x77867c, 0x74847a, 0x70837a, 0x778881, 0x869893, 0x9dadab, 0xb0bfbd, 0xb4c5c1, 0xccd8d5, 0x717d7f, 0x899394, 0xcbd1d3, 0x80858b, 0xe5e1e4, 0xbebec4, 0xd1ced6, 0xe0d8dd, 0xdaced6, 0xd1cad1, 0xcec9d3, 0x9fa6af, 0x979a90, 0x5b624b, 0x51593c, 0x6c6c5d, 0xb1b1b0, 0xbdbebc, 0x787a71, 0x787b74, 0x757c74, 0x727b73, 0x6e766f, 0x79847c, 0x77837a, 0x718078, 0x77857e, 0x899794, 0xa1adad, 0xb4bebd, 0xb8c5c2, 0xcbd4d4, 0x5c6466, 0x747977, 0xacacb0, 0x767c83, 0xdedbdd, 0xbfbec5, 0xd7d3d9, 0xe2d9de, 0xdaceda, 0xcfc8d0, 0xccc8d0, 0x92a2a9, 0x9fa197, 0x59624a, 0x505a3a, 0x6c6a5b, 0xb3b2b0, 0xc2c2c1, 0x787a74, 0x797c75, 0x797c76, 0x777b75, 0x6f7571, 0x7b827e, 0x78827c, 0x737e7a, 0x7a8581, 0x8e9899, 0xa6afb2, 0xb7bfc0, 0xbec6c8, 0xc3cbcd, 0x4b5352, 0x797a78, 0xa6a5a8, 0x828389, 0xd7d2d6, 0xc3c0c9, 0xdad1d6, 0xe5dadf, 0xd9cfd8, 0xcfc9cf, 0xcbc9cd, 0x929c9d, 0x999f95, 0x5c654c, 0x515b3c, 0x6c6a5b, 0xb1afae, 0xc8c5c5, 0x7b7b75, 0x7a7c75, 0x7b7d77, 0x7a7b77, 0x727572, 0x7e817e, 0x7d817d, 0x797f7c, 0x7f8784, 0x949a9c, 0xabb0b5, 0xbabec2, 0xc6cacd, 0xb7bbc1, 0x474f51, 0xcccccf, 0xe3e3e4, 0x8b8c92, 0xcdc8cc, 0xc5c1cb, 0xd9d0d8, 0xe6dce4, 0xd7d1d8, 0xcecad0, 0xccc9ce, 0x999490, 0x8e978f, 0x636851, 0x515a3c, 0x6a6a58, 0xada8a7, 0xcbc6c8, 0x7e7d78, 0x7b7c73, 0x7b7c78, 0x7a7a77, 0x747673, 0x80827f, 0x7e7e7c, 0x787d7b, 0x808885, 0x989b9d, 0xaeb1b7, 0xbcbdc3, 0xcfcfd4, 0x9d9ea6, 0x575b5f, 0xd0cdd4, 0xdad7dc, 0x8f9097, 0xc4bfc4, 0xc7c2cc, 0xdcd6db, 0xe4dbe4, 0xd7cfd7, 0xcecacf, 0xccc8cf, 0x9e9995, 0x8c948e, 0x676d57, 0x4e583a, 0x676756, 0xa69fa0, 0xcdc5c9, 0x817c79, 0x7d7b74, 0x7d7a76, 0x797771, 0x757370, 0x807f7d, 0x7b7b79, 0x797a79, 0x838685, 0x99999c, 0xb0aeb6, 0xbdbac1, 0xd6d3da, 0x7a7b7f, 0x707173, 0xded6de, 0xdcd3d9, 0xa5a5a9, 0xa9a7ad, 0xc8c3cd, 0xe2dce0, 0xddd6df, 0xd2cfd5, 0xcacbce, 0xc7c8cd


};

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}


static void vInferTask(void *pvParameters)
{

    while (1) {
        ei_printf("Edge Impulse standalone inferencing (Eta Compute ECM3532)\n");

        if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
            ei_printf("The size of your 'features' array is not correct. Expected %d items, but had %u\n",
                EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
            return;
        }

        ei_impulse_result_t result = { 0 };

        // the features are stored into flash, and we don't want to load everything into RAM at the same time
        // so we use a signal to wrap around the data
        signal_t features_signal;
        features_signal.total_length = sizeof(features) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        // invoke the impulse
        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, true);
        ei_printf("run_classifier returned: %d\n", res);

        if (res != 0) return;

        ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
            result.timing.dsp, result.timing.classification, result.timing.anomaly);

        // print the predictions
        ei_printf("[");
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
            ei_printf_float(result.classification[ix].value);
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
            ei_printf(", ");
    #else
            if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
                ei_printf(", ");
            }
    #endif
        }
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
        ei_printf_float(result.anomaly);
    #endif
        ei_printf("]\n");

        // And wait 5 seconds
        EtaCspRtcTmrDelayMs(5000);
    }
}

int main(void)
{
    EtaCspTimerDelayMs(2000);
    EtaCspUartInit(&etaUart, (tUartNum)CONFIG_DEBUG_UART, eUartBaud115200, eUartFlowControlNone);
    EtaCspTimerDelayMs(500);

	xTaskCreate(vInferTask, "standalone inference", TASK_STACK_SIZE,
                NULL, tskIDLE_PRIORITY + 3, NULL);

    	/* Start the scheduler. */
	vTaskStartScheduler();	
}