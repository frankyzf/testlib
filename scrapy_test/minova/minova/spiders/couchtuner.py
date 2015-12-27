# -*- coding: utf-8 -*-
import scrapy


class CouchtunerSpider(scrapy.Spider):
    name = "couchtuner"
    allowed_domains = ["couchtuner.fr"]
    start_urls = (
        'http://www.couchtuner.fr/watch-12-monkeys-online/',
        'http://www.couchtuner.fr/watch-2-broke-girls-online/',
    )

    def parse(self, response):
        for sel in response.xpath('//div[contains(@id, "content")]//div[contains(@class, "entry")]//ul/li'):
            name = sel.xpath('strong/text()').extract()
            link = sel.xpath('strong/a/@href').extract()
            print name, link


