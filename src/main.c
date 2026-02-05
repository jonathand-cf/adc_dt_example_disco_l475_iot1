#include <inttypes.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

static const struct adc_dt_spec adc_channel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));

int main(void)
{
	uint32_t count = 0;
	uint16_t buf;
	struct adc_sequence sequence = {
		.buffer = &buf,
		/* buffer size in bytes, not number of samples */
		.buffer_size = sizeof(buf),
	};

	while (1) {
		int32_t val_mv;

		printk("ADC reading[%u]:\n", count++);
		printk("- %s, channel %d: ",
		       adc_channel.dev->name,
		       adc_channel.channel_id);

		(void)adc_sequence_init_dt(&adc_channel, &sequence);
		(void)adc_read_dt(&adc_channel, &sequence);

		val_mv = (int32_t)buf;
		printk("%"PRId32, val_mv);
		adc_raw_to_millivolts_dt(&adc_channel, &val_mv);
		printk(" = %"PRId32" mV\n", val_mv);

		k_sleep(K_MSEC(1000));
	}
	return 0;
}
