# -*- coding: utf-8 -*-
import scrapy
from minova.items import MinovaItem


class CouchtunerSpider(scrapy.Spider):
    name = "couchtuner"
    allowed_domains = ["couchtuner.fr"]
    start_urls = (
        'http://www.couchtuner.fr/watch-2-broke-girls-online/',
    )

    def parse(self, response):
        for sel in response.xpath('//div[contains(@id, "content")]//div[contains(@class, "entry")]//ul/li'):
            item = MinovaItem()
            item['des'] = sel.xpath('strong/a/text()').extract()
            item['title'] = sel.xpath('strong/text()').extract()
            item['link'] = sel.xpath('strong/a/@href').extract()
            yield item


