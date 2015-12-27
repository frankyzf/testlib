# -*- coding: utf-8 -*-
import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider, Rule

from minova.items import MinovaItem


class CouchtunerIndexSpider(CrawlSpider):
    name = 'couchtuner_index'
    allowed_domains = ['couchtuner.fr']
    start_urls = ['http://www.couchtuner.fr/']

    rules = (
        Rule(LinkExtractor(allow=r'^$', restrict_xpaths='//div[contains(@id, "sidebar")]/div[contains(@id, "left")]//ul/li')),
        Rule(LinkExtractor(allow=r'^\S+$'), callback='parse_item'),
    )


    def parse_item(self, response):
        for sel in response.xpath('//div[contains(@id, "content")]//div[contains(@class, "entry")]//ul/li'):
            item = MinovaItem()
            item['des'] = sel.xpath('strong/a/text()').extract()
            item['title'] = sel.xpath('strong/text()').extract()
            item['link'] = sel.xpath('strong/a/@href').extract()
            print item
            yield item
