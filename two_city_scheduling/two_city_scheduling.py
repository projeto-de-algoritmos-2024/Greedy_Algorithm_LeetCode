class Solution(object):
    def twoCitySchedCost(self, costs):
        sorted_costs = sorted(costs, key=lambda x: abs(x[0] - x[1]), reverse=True)
        
        total_cost = 0
        A_count = 0
        B_count = 0
        n = len(costs) // 2

        for cost_a, cost_b in sorted_costs:
            if (A_count < n and (cost_a < cost_b or B_count == n)):
                total_cost += cost_a
                A_count += 1
            else:
                total_cost += cost_b
                B_count += 1

        return total_cost
