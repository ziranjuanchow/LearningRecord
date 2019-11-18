# Jira Rest Api
>JIRA 7.6.1

# Jira python lib


from lib.jira import JIRA

jira = JIRA('http://jira.digi-sky.com', basic_auth=('zhouhongwei', 'Digisky_2019'))
# jira = JIRA('http://jira.digi-sky.com/projects/JIRASHOTGU',basic_auth=('zhouhongwei', 'Digisky_2019'))

# search issue
issues = jira.search_issues('project=CSXM')
for index in issues:
    print index

print "------------------------------------------------------"

# get project
projects = jira.projects()
for index in projects:
    print index
print "------------------------------------------------------"

# get issue
print "xxxxxxxxxxxxxxxxxxxxx"
issue = jira.issue("CSXM-67")
print issue
print issue.raw
print "------------------------------------------------------"

# Find all comments made by Atlassians on this issue.
# atl_comments = [
#    comment
#    for comment in issue.fields.comment.comments
#    if re.search(r"@digisky.com$", comment.author.emailAddress)
# ]
# print atl_comments
# print "------------------------------------------------------"

# Add a comment to the issue.
# rtn1 = jira.add_comment(issue, "Comment text 1")
# print rtn1
# print "------------------------------------------------------"

# Change the issue's summary and description.
# issue.update(
#    summary="second version -2", description="second version -2."
# )

# Change the issue without sending updates
# 这个方法不行，会报错，之后看
# issue.update(notify=False, description="Quiet summary update.")

# You can update the entire labels field like this
# 改issue的标签
# issue.update(fields={"labels": ["test-1", "test-2"]})

# Or modify the List of existing labels. The new label is unicode with no
# spaces
# issue.fields.labels.append(u"new_text-1")
# issue.update(fields={"labels": issue.fields.labels})

# Send the issue away for good.
# issue.delete()

# Linking a remote jira issue (needs applinks to be configured to work)
# issue = jira.issue("JRA-1330")
# issue2 = jira.issue("XX-23")  # could also be another instance
# jira.add_remote_link(issue, issue2)

from collections import Counter

# Get the mutable application properties for this server (requires
# jira-system-administrators permission)
# props = jira.application_properties()
# print props
# print "------------------------------------------------------"

# Find all issues reported by the admin
# issues = jira.search_issues("assignee=admin")
# print issues
# print "------------------------------------------------------"

# Find the top three projects containing issues reported by admin
# top_three = Counter([issue.fields.project.key for issue in issues]).most_common(3)
# print top_three
# print "------------------------------------------------------"

# This example shows how to work with GreenHopper:
# This script shows how to use the client in anonymous mode
from lib.jira.client import GreenHopper

# By default, the client will connect to a JIRA instance started from the Atlassian Plugin SDK
# (see https://developer.atlassian.com/display/DOCS/Installing+the+Atlassian+Plugin+SDK for details).
# Override this with the options parameter.
# GreenHopper is a plugin in a JIRA instance
# options = {"server": "http://jira.digi-sky.com/"}
# gh = GreenHopper(options)
# gh = JIRA(options)
# print gh
# print "------------------------------------------------------"

# Get all boards viewable by anonymous users.
# boards = gh.boards()
# print boards
# boards = jira.boards()
# print boards
# for index in boards:
#    print index
# print "------------------------------------------------------"

# create_version
# create project
# create sprint
# create_component
# create_filter
# create_issue
# create_issues
# create_customer
# create_customer_request
# createmeta
# create_issue_link
# create_temp_project_avatar
# create_temp_user_avatar
# create_board

# issue2 = jira.create_issue()
###create_issue test
issue_dict = {
    "project": {"key": "CSXM"},  # 项目
    "issuetype": {"name": "任务"},  # 问题类型
    "summary": "model_model_chr_sam_2",  # 问题主题
    "components": [{"name": "美术"}],  # 相关模块
    "assignee": {"name": "zhouhongwei"},  # 经办人
    "reporter": {"name": "duhaidong"}, #报告人
    "description": "模型制作任务，不包含uv/材质/贴图",  # 问题描述
    "fixVersions": [{"name": "V3.0.0"}],  # 修复版本
    "customfield_10438": "2019-11-18",  # 开始日期
    "versions": [{"name": "V3.0.0"}],  # 影响版本
    "duedate": "2019-11-21",  # 到期日
    "timetracking": {"originalEstimate": "4d",  # 初始预估
                     "remainingEstimate": "3d"  # 剩余的估算
                     }
}

#issue2 = jira.create_issue(fields=issue_dict)
#issue2 = jira.create_issue(project='JIRASHOTGU', summary='New issue from jira-python',
#                           description='Look into this one', issuetype={'name': 'Bug'})
#print issue2
