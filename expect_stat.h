#include <cstdio>
#include <cstdint>	/* For std::uint64_t */
#include <atomic>

/*
A simple class for determining the preferred branch of IF. To use, you must
include this header and insert methods into both branches of the condition being
investigated. When the program being investigated completes, the counter values
will be output. The larger the value, the preferred branch, into which the
likely attribute should be inserted.
*/

template <typename L>
class ExpectStat {
public:
	void if_inc() {
            m_if_cnt.fetch_add(1, std::memory_order_release);
	}

	void else_inc() {
            m_else_cnt.fetch_add(1, std::memory_order_release);
	}

	~ExpectStat() {
		std::printf("If counter: %lu\n", m_if_cnt.load(std::memory_order_acquire));
		std::printf("Else counter: %lu\n", m_else_cnt.load(std::memory_order_acquire));
	}
private:
	std::atomic<L> m_if_cnt { 0 };
	std::atomic<L> m_else_cnt { 0 };
};

ExpectStat<std::uint64_t> es;
